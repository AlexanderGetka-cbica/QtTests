#include "fAppDownloadDialog.h"
//#include "fProgressDialog.h"
//#include "CAPTk.h"
//#include "CaPTkGUIUtils.h"

//#include "cbicaITKUtilities.h"

#include "ApplicationPreferences.h"

fAppDownloadDialog::fAppDownloadDialog()
{
  setupUi(this);
  this->setWindowModality(Qt::NonModal);
  this->setModal(true); // this is a pre-processing routine and therefore should be modal
  this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

  // progressDialog = new QProgressDialog(this);

  connect(cancelButton, SIGNAL(clicked()), this, SLOT(CancelButtonPressed()));
  connect(confirmButton, SIGNAL(clicked()), this, SLOT(ConfirmButtonPressed()));
  // connect(outputImageButton, SIGNAL(clicked()), this, SLOT(SelectOutputDirectory()));
  // connect(modelImageButton, SIGNAL(clicked()), this, SLOT(SelectModelDirectory()));
  // connect(brainTumorSegmentationButton, SIGNAL(toggled(bool)), this, SLOT(SetDefaultModel()));
  // connect(skullStrippingButton, SIGNAL(toggled(bool)), this, SLOT(SetDefaultModel()));
  // connect(customButton, SIGNAL(toggled(bool)), this, SLOT(SetDefaultModel()));
  // //connect(brainTumorSegmentationButton, SIGNAL(toggled(bool)), this, [this] { SetDefaultModel(fAppDownloadDialog::Tumor); });

  // outputDirName->setText(mInputPathName);
  // m_baseModelDir = cbica::normPath(getCaPTkDataDir() + "/deepMedic/saved_models/");

  // m_exe = getApplicationPath("DeepMedic").c_str();

  // m_dataDir = getCaPTkDataDir().c_str();
}
fAppDownloadDialog::~fAppDownloadDialog()
{
}

void fAppDownloadDialog::CancelButtonPressed()
{
    this->close();
}

void fAppDownloadDialog::ConfirmButtonPressed()
{
    ApplicationPreferences::GetInstance()->DeSerializePreferences();
    bool downloadStarted = QVariant(ApplicationPreferences::GetInstance()->GetLibraDownloadStartedStatus()).toBool();
    bool downloadFinished = QVariant(ApplicationPreferences::GetInstance()->GetLibraDownloadFinishedStatus()).toBool();
    bool extractionStarted = QVariant(ApplicationPreferences::GetInstance()->GetLibraExtractionStartedStatus()).toBool();
    bool extractionFinished = QVariant(ApplicationPreferences::GetInstance()->GetLibraExtractionFinishedStatus()).toBool();

    if(extractionFinished)
    {
        QMessageBox::information(this,tr("Download"),"Already Downloaded");
    }
    else if(downloadStarted && !downloadFinished)
    {
        QMessageBox::information(this,tr("Download"),"Download in progress");
    }
    else if(extractionStarted && !extractionFinished)
    {
        QMessageBox::information(this,tr("Download"),"Extraction in progress");
    }
    else
    {

        // progressDialog = new QProgressDialog(this);
        setupDownload(this);

        connect(progressDialog, SIGNAL(canceled()), this, SLOT(cancelDownload()));

        manager = new QNetworkAccessManager(this);

        // url =
        QFileInfo fileInfo(url.path());
        QString fileName = fileInfo.fileName();

        if (fileName.isEmpty())
            fileName = "index.html";

        this->fullPath = downloadPath + "/" + fileName;
        //   ShowErrorMessage(fullPath.toStdString(), this);

        qDebug() << " filename = " << fileName << endl;
        qDebug() << "full path = " << fullPath << endl;

        if (QFile::exists(fullPath)) {
            if (QMessageBox::question(this, tr("HTTP"),
                                      tr("There already exists a file %1. Overwrite?").arg(fileName),
                                      QMessageBox::Yes|QMessageBox::No, QMessageBox::No)
                    == QMessageBox::No)
                return;
            QFile::remove(fullPath);
        }

        file = new QFile(fullPath);
        if (!file->open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("HTTP"),
                                     tr("Unable to save the file %1: %2")
                                     .arg(fileName).arg(file->errorString()));
            delete file;
            file = 0;
            return;
        }

        ApplicationPreferences::GetInstance()->SetLibraDownloadStartedStatus(QVariant("true").toString());
        ApplicationPreferences::GetInstance()->SerializePreferences();

        // used for progressDialog
        // This will be set true when canceled from progress dialog
        httpRequestAborted = false;

        progressDialog->setWindowTitle(tr("HTTP"));
        progressDialog->setLabelText(tr("Downloading %1.").arg(fileName));

        // download button disabled after requesting download
        // ui->downloadButton->setEnabled(false);

        startRequest(url);

        //emit doneDownload(fullPath.toStdString());

        this->close();
    }
}


// This will be called when download button is clicked
void fAppDownloadDialog::startRequest(QUrl url)
{
    // get() method posts a request
    // to obtain the contents of the target request
    // and returns a new QNetworkReply object
    // opened for reading which emits
    // the readyRead() signal whenever new data arrives.
    reply = manager->get(QNetworkRequest(url));

    // Whenever more data is received from the network,
    // this readyRead() signal is emitted
    connect(reply, SIGNAL(readyRead()),
            this, SLOT(httpReadyRead()));

    // Also, downloadProgress() signal is emitted when data is received
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)),
            this, SLOT(updateDownloadProgress(qint64,qint64)));

    // This signal is emitted when the reply has finished processing.
    // After this signal is emitted,
    // there will be no more updates to the reply's data or metadata.
    connect(reply, SIGNAL(finished()),
            this, SLOT(httpDownloadFinished()));
}


void fAppDownloadDialog::httpReadyRead()
{
    // this slot gets called every time the QNetworkReply has new data.
    // We read all of its new data and write it into the file.
    // That way we use less RAM than when reading it at the finished()
    // signal of the QNetworkReply
    if (file)
        file->write(reply->readAll());
}

void fAppDownloadDialog::updateDownloadProgress(qint64 bytesRead, qint64 totalBytes)
{
    if (httpRequestAborted)
        return;

    progressDialog->setMaximum(totalBytes);
    progressDialog->setValue(bytesRead);
}

// When download finished or canceled, this will be called
void fAppDownloadDialog::httpDownloadFinished()
{
  // when canceled
    if (httpRequestAborted) {
        if (file) {
            file->close();
            file->remove();
            delete file;
            file = 0;
        }
        reply->deleteLater();
        progressDialog->hide();
        return;
    }

    ApplicationPreferences::GetInstance()->SetLibraDownloadFinishedStatus(QVariant("true").toString());
    ApplicationPreferences::GetInstance()->SerializePreferences();

    // download finished normally
    progressDialog->hide();
    file->flush();
    file->close();

    // get redirection url
    QVariant redirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if (reply->error()) {
        file->remove();
        QMessageBox::information(this, tr("HTTP"),
                                tr("Download failed: %1.")
                                .arg(reply->errorString()));
        // ui->downloadButton->setEnabled(true  );
    } else if (!redirectionTarget.isNull()) {
        QUrl newUrl = url.resolved(redirectionTarget.toUrl());
        if (QMessageBox::question(this, tr("HTTP"),
                                tr("Redirect to %1 ?").arg(newUrl.toString()),
                                QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
            url = newUrl;
            reply->deleteLater();
            file->open(QIODevice::WriteOnly);
            file->resize(0);
            startRequest(url);
            return;
        }
    } else {
        QString fileName = QFileInfo(QUrl(qInputLink).path()).fileName();
        // ui->statusLabel->setText(tr("Downloaded %1 to %2.").arg(fileName).arg(QDir::currentPath()));
        // ui->downloadButton->setEnabled(true);
    }

    qDebug() << " qinputlink = " << qInputLink << endl;
    reply->deleteLater();
    reply = 0;
    delete file;
    file = 0;
    manager = 0;

    emit doneDownload(this->fullPath.toStdString());
}

// During the download progress, it can be canceled
void fAppDownloadDialog::cancelDownload()
{
    // ui->statusLabel->setText(tr("Download canceled."));
    httpRequestAborted = true;
    reply->abort();
    // ui->downloadButton->setEnabled(true);
    this->close();
}
