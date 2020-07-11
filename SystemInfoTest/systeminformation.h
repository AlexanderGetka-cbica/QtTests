#ifndef SYSTEMINFORMATION_H
#define SYSTEMINFORMATION_H

#include <QStringList>

class SystemInformation
{
public:
    SystemInformation();
    ~SystemInformation() = default;

   QStringList GetSystemInformation();

private:

    void GetBasicInformation();
    void GetStorageInformation();
    void GetNetworkInformation();
    void GetRAMInformation();
    void GetOpenGLInformation();
    void GetGPUInformation();
    void GetOSInformation();
    void PrintInformation();//for debugging purposes only

    //! Get GPU information
    //void GetGPUInformation();

   QStringList m_InfoList;
};

#endif // SYSTEMINFORMATION_H
