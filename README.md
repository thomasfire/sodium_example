# sodium_example

## Build and run tests
### Generic Unix:
Needs cmake and C compiler being installed.
```shell
# download repo and enter its root directory
# ....
$ cmake -S . -B build
$ cmake --build build
$ cmake --build abuild -t test
```

### Android device:
Download and extract Android NDK from https://developer.android.com/ndk/downloads.
Then
```shell
# download repo and enter its root directory
# ....
$ cmake -S . -B build -DCMAKE_SYSTEM_NAME=Android \
  -DCMAKE_SYSTEM_VERSION=24 \
  -DCMAKE_ANDROID_ARCH_ABI=arm64-v8a  \
  -DCMAKE_ANDROID_NDK=/path/to/android_ndk
$ cmake --build build
# connect your device via ADB and ensure adb shell works
# ....
$ cmake --build build -t test
```
This test script will load executable into your device and run it with test input.

### Additional
You may want to use raw output instead of HEX, in this case uncomment `target_compile_definitions(${PROJECT_NAME} PRIVATE PRINT_HEX=0)` line in the CMakeLists.txt.