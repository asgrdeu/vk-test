$build_dir_root = "./";
$build_dir_name = "build";
$build_dir_path = "./build";

if (Test-Path -Path $build_dir_path) {
    Write-Output "Removing build directory..."
    Remove-Item -LiteralPath $build_dir_path -Force -Recurse;
} else {
    Write-Output "Build directory is not exist. Make build directory..."
    New-Item -Path $build_dir_root -Name $build_dir_name -ItemType "directory"
}

cmake -G "Unix Makefiles" -B $build_dir_path

if ($?) {
    cmake --build $build_dir_path
}

if ($?) {
    powershell "$build_dir_path/bin/vk-test_physx.exe"
    powershell "$build_dir_path/bin/vk-test_vk.exe"
}

