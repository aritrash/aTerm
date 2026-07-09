#define MyAppName "aTerm"
#define MyAppVersion "0.2.0"
#define MyAppPublisher "Aether Research"
#define MyAppURL "https://github.com/aritrash/aTerm"
#define MyAppExeName "aTerm.exe"

[Setup]
AppId={{A0A53E91-13B5-4B5D-9D80-6A2B2B04A001}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={autopf}\{#MyAppName}
DefaultGroupName={#MyAppName}
DisableProgramGroupPage=yes
LicenseFile=LICENSE
OutputDir=installer
OutputBaseFilename=aTerm-v0.2.0-Setup
Compression=lzma2
SolidCompression=yes
WizardStyle=modern
ArchitecturesAllowed=x64
ArchitecturesInstallIn64BitMode=x64
SetupIconFile=dist\aTerm.ico

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "Create a desktop shortcut"; GroupDescription: "Additional icons:"

[Files]
Source: "dist\*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]
Name: "{autoprograms}\aTerm"; Filename: "{app}\aTerm.exe"
Name: "{autodesktop}\aTerm"; Filename: "{app}\aTerm.exe"; Tasks: desktopicon

[Run]
Filename: "{app}\aTerm.exe"; Description: "Launch aTerm"; Flags: nowait postinstall skipifsilent