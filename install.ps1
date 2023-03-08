#Execute this script only on window in Visual studio (need msbuild)

function help {
	write-host "USAGE: ./install.sh Commands"
    write-host "Installer for R-Type on Windows"
    write-host "Commands:"
    write-host "build         Try to Build the project"
    write-host "clean         Clean the project"
}

function createShortCut {
    $Path = (pwd).Path
    $SourceFilePath = "$Path\r-type_client.exe"
    $ShortcutPath = "$Path\r-type_client.lnk"
    $WScriptObj = New-Object -ComObject ("WScript.Shell")
    $shortcut = $WscriptObj.CreateShortcut($ShortcutPath)
    $shortcut.TargetPath = $SourceFilePath
    $shortcut.Save()
}

function mvAllAtRoot {
    cp .\build\_deps\sdl2-build\Debug\SDL2d.dll .
    cp .\build\_deps\sdl2_ttf-build\Debug\SDL2_ttfd.dll .
    cp .\build\_deps\sdl2_image-build\Debug\SDL2_imaged.dll .
    cp .\build\_deps\sdl2_mixer-build\Debug\SDL2_mixerd.dll .
    cp .\build\GameEngine\Debug\GameEngine.dll .
    cp .\build\GameEngine\Debug\Network.dll .
    cp .\build\client\Debug\r-type_client.exe .
    cp .\build\server\Debug\r-type_server.exe .
}

function buildAll {
    tar -xf .\assets.zip
    cd build
    cmake ../ -DSDL2MIXER_VENDORED=OFF -DSDL2MIXER_FLAC=OFF -DSDL2MIXER_MOD=OFF -DSDL2MIXER_MIDI=OFF -DSDL2MIXER_OPUS=OFF
    msbuild r-type.sln
    msbuild r-type.sln
    cd ../
    mvAllAtRoot
    createShortCut
    cp .\r-type_client.lnk $Home\Desktop
}

if ($args[0] -match	'build') {
    buildAll
} elseif ($args[0] -match 'clean') {

} else {
	help
}