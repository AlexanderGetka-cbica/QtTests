#include "systeminformation.h"
#include <QOperatingSystemVersion>
#include <QStorageInfo>
#include <QNetworkInterface>

//#include <vtkGPUInfoList.h>
//#include <vtkGPUInfo.h>

// For getting the total amount of installed ram
#ifdef _WIN32
#include <windows.h>
#else
// For both linux + mac
#include <unistd.h>
#endif

//QStringList SystemInformation::m_InfoList = QStringList();

SystemInformation::SystemInformation()
{
    this->GetBasicInformation();
    this->GetStorageInformation();
    this->GetNetworkInformation();
    this->GetRAMInformation();
    this->GetOpenGLInformation();
    this->GetGPUInformation();
    this->GetOSInformation();
    //this->GetGPUInformation();
}

QStringList SystemInformation::GetSystemInformation()
{
    //PrintInformation();
    return m_InfoList;
}

void SystemInformation::GetBasicInformation()
{
    //basic
    QSysInfo systemInfo;
    //this->m_InfoList << "Windows Version: " + systemInfo.windowsVersion(); //deprecated
    this->m_InfoList << "Build Cpu Architecture: " + systemInfo.buildCpuArchitecture();
    this->m_InfoList << "Current Cpu Architecture: " + systemInfo.currentCpuArchitecture();
    this->m_InfoList << "Kernel Type: " + systemInfo.kernelType();
    this->m_InfoList << "Kernel Version: " + systemInfo.kernelVersion();
    this->m_InfoList << "Machine Host Name: " + systemInfo.machineHostName();
    this->m_InfoList << "Product Type: " + systemInfo.productType();
    this->m_InfoList << "Product Version: " + systemInfo.productVersion();
    this->m_InfoList << "Byte Order: " + systemInfo.buildAbi();
    this->m_InfoList << "Pretty ProductName: " + systemInfo.prettyProductName();
}

void SystemInformation::GetStorageInformation()
{
    //storage specific
    for (auto volume : QStorageInfo::mountedVolumes())
    {
        if (volume.isValid() && volume.isReady())
        {
            this->m_InfoList << "Name: " + volume.name();
            this->m_InfoList << "Display name: " + volume.displayName();
            this->m_InfoList << "Device: " + volume.device();
            this->m_InfoList << "Root path: " + volume.rootPath();
            this->m_InfoList << "File system type: " + volume.fileSystemType();
            this->m_InfoList << "Is valid? " + QString(volume.isValid() ? "yes" : "no");
            //this->m_InfoList << "Is root? " + (volume.isRoot() ? "yes" : "no");
            this->m_InfoList << "Is ready? " + QString(volume.isReady() ? "yes" : "no");
            this->m_InfoList << "Is read only? " + QString(volume.isReadOnly() ? "yes" : "no");
            this->m_InfoList << "Bytes available: " + QString::number(volume.bytesAvailable()/1000000000) +  "GB";
            this->m_InfoList << "Bytes free: " + QString::number(volume.bytesFree()/1000000000) +  "GB";
            this->m_InfoList << "Bytes total: " + QString::number(volume.bytesTotal()/1000000000) +  "GB";
        }
    }
}

void SystemInformation::GetNetworkInformation()
{
    //network specific
    foreach(QNetworkInterface networkInterface, QNetworkInterface::allInterfaces())
     {
         if (networkInterface.flags().testFlag(QNetworkInterface::IsUp) && !networkInterface.flags().testFlag(QNetworkInterface::IsLoopBack))
         {
             foreach (QNetworkAddressEntry entry, networkInterface.addressEntries())
             {
                 if ( entry.ip().toString().contains(".")){
                     this->m_InfoList << "Interface: " + networkInterface.name();
                     this->m_InfoList << "IP: " + entry.ip().toString();
                     this->m_InfoList << "MAC: "  + networkInterface.hardwareAddress();
                 }
             }
         }
     }
}

void SystemInformation::GetRAMInformation()
{
    unsigned long long ram;
    #ifdef _WIN32
      MEMORYSTATUSEX status;
      status.dwLength = sizeof(status);
      GlobalMemoryStatusEx(&status);
      ram = status.ullTotalPhys;
    #else
      long pages = sysconf(_SC_PHYS_PAGES);
      long page_size = sysconf(_SC_PAGE_SIZE);
      ram = pages * page_size;
    #endif
      this->m_InfoList << "RAM: " + QString::number(ram/(1024.0*1024*1024),'f',2) + "GB";
}

void SystemInformation::GetOpenGLInformation()
{
    //    //opengl
    //    QOpenGLContext ctx;
    //    QOffscreenSurface srfc;
    //    bool status = ctx.create();
    //    ctx.makeCurrent(&srfc);
    //    if( status )
    //        qDebug() << "opengl context created ";
    //    if(ctx.isValid())
    //        qDebug() << "opengl context valid";

    //    QOpenGLFunctions* f = ctx.functions();
    //    //QOpenGLContext* ctx = QOpenGLContext::currentContext();
    //    //if (QOpenGLFunctions* f = &ctx ? ctx.functions() : nullptr)
    //    {
    //      const char* glVendor = reinterpret_cast<const char*>(f->glGetString(GL_VENDOR));
    //      const char* glRenderer = reinterpret_cast<const char*>(f->glGetString(GL_RENDERER));
    //      const char* glVersion = reinterpret_cast<const char*>(f->glGetString(GL_VERSION));
    //      qDebug() << "OpenGL Vendor " << glVendor;
    //      qDebug() << "OpenGL Version " << glVersion;
    //      qDebug() << "OpenGL Renderer " << glRenderer;
    //    }
}

void SystemInformation::GetGPUInformation()
{

}

void SystemInformation::GetOSInformation()
{
    qDebug() << "SystemInformation::GetOSInformation()";
    m_InfoList << "OS Version: " + QOperatingSystemVersion::current().name();
    this->m_InfoList << "Major OS Version: " + QString::number(QOperatingSystemVersion::current().majorVersion());
    this->m_InfoList << "Minor Version: " + QString::number(QOperatingSystemVersion::current().minorVersion());
    this->m_InfoList << "Micro Version: " + QString::number(QOperatingSystemVersion::current().microVersion());

}

void SystemInformation::PrintInformation()
{
    qDebug() << "SystemInformation::PrintInformation()";
    foreach(QString s, m_InfoList)
    {
        qDebug() << s;
    }
}

//void SystemInformation::GetGPUInformation()
//{
//	vtkGPUInfoList *l = vtkGPUInfoList::New();
//	l->Probe();
//	int nGPUs = l->GetNumberOfGPUs();
//	if (nGPUs > 0)
//	{
//		this->m_InfoList << "****GPU Information****";
//		this->m_InfoList << "Number of GPUs found: " + QString::number(nGPUs);
//		for (int i = 0; i < nGPUs; i++)
//		{
//			vtkGPUInfo *info = l->GetGPUInfo(i);
//			vtkTypeUInt64 videomem = info->GetDedicatedVideoMemory();
//			vtkTypeUInt64 systemmem = info->GetDedicatedSystemMemory();
//			vtkTypeUInt64 sharedsystemmem = info->GetSharedSystemMemory();

//			this->m_InfoList << "Dedicated Video Memory: " + QString::number(videomem / (1024.0 * 1024 * 1024), 'f', 2) + "GB";
//			this->m_InfoList << "Dedicated System Memory: " + QString::number(systemmem / (1024.0 * 1024 * 1024), 'f', 2) + "GB";
//			this->m_InfoList << "Shared System Memory: " + QString::number(sharedsystemmem / (1024.0 * 1024 * 1024), 'f', 2) + "GB";
//		}
//		this->m_InfoList << "\n";
//	}
//	l->Delete();
//}
