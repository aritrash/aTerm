#define MyAppName "aTerm"
#define MyAppVersion "0.2.1"
#define MyAppPublisher "Asta Epsilon Group"
#define MyAppURL "https://github.com/aritrash/aTerm"
#define MyAppExeName "aTerm.exe"

[Setup]
AppId={{5B6A9A8D-0A8B-4E5F-8C41-6B2A9F0A1234}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}

DefaultDirName={autopf}\aTerm
DefaultGroupName=aTerm

OutputDir=dist
OutputBaseFilename=aTerm-Setup-v0.2.1

Compression=lzma2
SolidCompression=yes
WizardStyle=modern

PrivilegesRequired=admin
ArchitecturesAllowed=x64compatible
ArchitecturesInstallIn64BitMode=x64compatible

UninstallDisplayIcon={app}\aTerm.exe

LicenseFile=LICENSE

SetupIconFile=assets\aTerm.ico

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "Create a Desktop Shortcut"; GroupDescription: "Additional Icons:"; Flags: unchecked

[Files]
Source: "build-release\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "README.md"; DestDir: "{app}"; Flags: ignoreversion
Source: "CHANGELOG.md"; DestDir: "{app}"; Flags: ignoreversion
Source: "LICENSE"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\aTerm"; Filename: "{app}\aTerm.exe"
Name: "{group}\Uninstall aTerm"; Filename: "{uninstallexe}"
Name: "{autodesktop}\aTerm"; Filename: "{app}\aTerm.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\aTerm.exe"; Description: "Launch aTerm"; Flags: nowait postinstall skipifsilent