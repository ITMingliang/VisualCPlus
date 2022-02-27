; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDemoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "demo.h"
LastPage=0

ClassCount=3
Class1=CDemoApp
Class2=CAboutDlg
Class3=CDemoDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDD_DEMO_DIALOG
Resource3=IDR_MENU

[CLS:CDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=Demo.h
ImplementationFile=Demo.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=DemoDlg.cpp
ImplementationFile=DemoDlg.cpp
LastObject=ID_EXIT

[CLS:CDemoDlg]
Type=0
BaseClass=CDialog
HeaderFile=DemoDlg.h
ImplementationFile=DemoDlg.cpp

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DEMO_DIALOG]
Type=1
Class=CDemoDlg
ControlCount=1
Control1=IDC_TEST,button,1342242816

[MNU:IDR_MENU]
Type=1
Class=?
Command1=ID_SHOW
Command2=ID_EXIT
CommandCount=2

