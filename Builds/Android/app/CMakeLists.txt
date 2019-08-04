# Automatically generated makefile, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

cmake_minimum_required(VERSION 3.4.1)

SET(BINARY_NAME "juce_jni")

add_library("cpufeatures" STATIC "${ANDROID_NDK}/sources/android/cpufeatures/cpu-features.c")
set_source_files_properties("${ANDROID_NDK}/sources/android/cpufeatures/cpu-features.c" PROPERTIES COMPILE_FLAGS "-Wno-sign-conversion -Wno-gnu-statement-expression")

add_definitions("-DJUCE_ANDROID=1" "-DJUCE_ANDROID_API_VERSION=16" "-DJUCE_PUSH_NOTIFICATIONS=1" "-DJUCER_ANDROIDSTUDIO_7F0E4A25=1" "-DJUCE_APP_VERSION=0.1" "-DJUCE_APP_VERSION_HEX=0x100")

include_directories( AFTER
    "../../../JuceLibraryCode"
    "~/JUCE/modules"
    "${ANDROID_NDK}/sources/android/cpufeatures"
)

enable_language(ASM)

IF(JUCE_BUILD_CONFIGURATION MATCHES "DEBUG")
    add_definitions("-DDEBUG=1" "-D_DEBUG=1")
ELSEIF(JUCE_BUILD_CONFIGURATION MATCHES "RELEASE")
    add_definitions("-DNDEBUG=1")
    if(NOT (ANDROID_ABI STREQUAL "mips" OR ANDROID_ABI STREQUAL "mips64"))
        SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -flto")
        SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -flto")
        SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -flto")
    ENDIF(NOT (ANDROID_ABI STREQUAL "mips" OR ANDROID_ABI STREQUAL "mips64"))
ELSE(JUCE_BUILD_CONFIGURATION MATCHES "DEBUG")
    MESSAGE( FATAL_ERROR "No matching build-configuration found." )
ENDIF(JUCE_BUILD_CONFIGURATION MATCHES "DEBUG")

add_library( ${BINARY_NAME}

    SHARED

    "../../../Source/DensePixelShape.cpp"
    "../../../Source/DensePixelShape.h"
    "../../../Source/SystemHeapStack.h"
    "../../../Source/DSU.cpp"
    "../../../Source/DSU.h"
    "../../../Source/Triple.h"
    "../../../Source/Menu.h"
    "../../../Source/Menu.cpp"
    "../../../Source/PointsToDraw.cpp"
    "../../../Source/PointsToDraw.h"
    "../../../Source/Color.h"
    "../../../Source/Shape.h"
    "../../../Source/PixelShape.cpp"
    "../../../Source/PixelShape.h"
    "../../../Source/GreatColor.cpp"
    "../../../Source/GreatColor.h"
    "../../../Source/CustomTimer.cpp"
    "../../../Source/CustomTimer.h"
    "../../../Source/MazeGenerator.cpp"
    "../../../Source/MazeGenerator.h"
    "../../../Source/OpenGLDrawer.cpp"
    "../../../Source/OpenGLDrawer.h"
    "../../../Source/Pair.h"
    "../../../Source/Application.cpp"
    "../../../Source/Application.h"
    "../../../Source/CentralComponent.cpp"
    "../../../Source/CentralComponent.h"
    "../../../Source/main.cpp"
    "../../../Source/MainForm.cpp"
    "../../../Source/MainForm.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_AbstractFifo.cpp"
    "../../../../../JUCE/modules/juce_core/containers/juce_AbstractFifo.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_Array.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_ArrayAllocationBase.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_ArrayBase.cpp"
    "../../../../../JUCE/modules/juce_core/containers/juce_ArrayBase.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_DynamicObject.cpp"
    "../../../../../JUCE/modules/juce_core/containers/juce_DynamicObject.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_ElementComparator.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_HashMap.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_HashMap_test.cpp"
    "../../../../../JUCE/modules/juce_core/containers/juce_LinkedListPointer.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_ListenerList.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_NamedValueSet.cpp"
    "../../../../../JUCE/modules/juce_core/containers/juce_NamedValueSet.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_OwnedArray.cpp"
    "../../../../../JUCE/modules/juce_core/containers/juce_OwnedArray.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_PropertySet.cpp"
    "../../../../../JUCE/modules/juce_core/containers/juce_PropertySet.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.cpp"
    "../../../../../JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_ScopedValueSetter.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_SortedSet.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_SparseSet.cpp"
    "../../../../../JUCE/modules/juce_core/containers/juce_SparseSet.h"
    "../../../../../JUCE/modules/juce_core/containers/juce_Variant.cpp"
    "../../../../../JUCE/modules/juce_core/containers/juce_Variant.h"
    "../../../../../JUCE/modules/juce_core/files/juce_DirectoryIterator.cpp"
    "../../../../../JUCE/modules/juce_core/files/juce_DirectoryIterator.h"
    "../../../../../JUCE/modules/juce_core/files/juce_File.cpp"
    "../../../../../JUCE/modules/juce_core/files/juce_File.h"
    "../../../../../JUCE/modules/juce_core/files/juce_FileFilter.cpp"
    "../../../../../JUCE/modules/juce_core/files/juce_FileFilter.h"
    "../../../../../JUCE/modules/juce_core/files/juce_FileInputStream.cpp"
    "../../../../../JUCE/modules/juce_core/files/juce_FileInputStream.h"
    "../../../../../JUCE/modules/juce_core/files/juce_FileOutputStream.cpp"
    "../../../../../JUCE/modules/juce_core/files/juce_FileOutputStream.h"
    "../../../../../JUCE/modules/juce_core/files/juce_FileSearchPath.cpp"
    "../../../../../JUCE/modules/juce_core/files/juce_FileSearchPath.h"
    "../../../../../JUCE/modules/juce_core/files/juce_MemoryMappedFile.h"
    "../../../../../JUCE/modules/juce_core/files/juce_TemporaryFile.cpp"
    "../../../../../JUCE/modules/juce_core/files/juce_TemporaryFile.h"
    "../../../../../JUCE/modules/juce_core/files/juce_WildcardFileFilter.cpp"
    "../../../../../JUCE/modules/juce_core/files/juce_WildcardFileFilter.h"
    "../../../../../JUCE/modules/juce_core/javascript/juce_Javascript.cpp"
    "../../../../../JUCE/modules/juce_core/javascript/juce_Javascript.h"
    "../../../../../JUCE/modules/juce_core/javascript/juce_JSON.cpp"
    "../../../../../JUCE/modules/juce_core/javascript/juce_JSON.h"
    "../../../../../JUCE/modules/juce_core/logging/juce_FileLogger.cpp"
    "../../../../../JUCE/modules/juce_core/logging/juce_FileLogger.h"
    "../../../../../JUCE/modules/juce_core/logging/juce_Logger.cpp"
    "../../../../../JUCE/modules/juce_core/logging/juce_Logger.h"
    "../../../../../JUCE/modules/juce_core/maths/juce_BigInteger.cpp"
    "../../../../../JUCE/modules/juce_core/maths/juce_BigInteger.h"
    "../../../../../JUCE/modules/juce_core/maths/juce_Expression.cpp"
    "../../../../../JUCE/modules/juce_core/maths/juce_Expression.h"
    "../../../../../JUCE/modules/juce_core/maths/juce_MathsFunctions.h"
    "../../../../../JUCE/modules/juce_core/maths/juce_NormalisableRange.h"
    "../../../../../JUCE/modules/juce_core/maths/juce_Random.cpp"
    "../../../../../JUCE/modules/juce_core/maths/juce_Random.h"
    "../../../../../JUCE/modules/juce_core/maths/juce_Range.h"
    "../../../../../JUCE/modules/juce_core/maths/juce_StatisticsAccumulator.h"
    "../../../../../JUCE/modules/juce_core/memory/juce_Atomic.h"
    "../../../../../JUCE/modules/juce_core/memory/juce_ByteOrder.h"
    "../../../../../JUCE/modules/juce_core/memory/juce_ContainerDeletePolicy.h"
    "../../../../../JUCE/modules/juce_core/memory/juce_HeapBlock.h"
    "../../../../../JUCE/modules/juce_core/memory/juce_HeavyweightLeakedObjectDetector.h"
    "../../../../../JUCE/modules/juce_core/memory/juce_LeakedObjectDetector.h"
    "../../../../../JUCE/modules/juce_core/memory/juce_Memory.h"
    "../../../../../JUCE/modules/juce_core/memory/juce_MemoryBlock.cpp"
    "../../../../../JUCE/modules/juce_core/memory/juce_MemoryBlock.h"
    "../../../../../JUCE/modules/juce_core/memory/juce_OptionalScopedPointer.h"
    "../../../../../JUCE/modules/juce_core/memory/juce_ReferenceCountedObject.h"
    "../../../../../JUCE/modules/juce_core/memory/juce_ScopedPointer.h"
    "../../../../../JUCE/modules/juce_core/memory/juce_SharedResourcePointer.h"
    "../../../../../JUCE/modules/juce_core/memory/juce_Singleton.h"
    "../../../../../JUCE/modules/juce_core/memory/juce_WeakReference.h"
    "../../../../../JUCE/modules/juce_core/misc/juce_ConsoleApplication.cpp"
    "../../../../../JUCE/modules/juce_core/misc/juce_ConsoleApplication.h"
    "../../../../../JUCE/modules/juce_core/misc/juce_Result.cpp"
    "../../../../../JUCE/modules/juce_core/misc/juce_Result.h"
    "../../../../../JUCE/modules/juce_core/misc/juce_RuntimePermissions.cpp"
    "../../../../../JUCE/modules/juce_core/misc/juce_RuntimePermissions.h"
    "../../../../../JUCE/modules/juce_core/misc/juce_StdFunctionCompat.cpp"
    "../../../../../JUCE/modules/juce_core/misc/juce_StdFunctionCompat.h"
    "../../../../../JUCE/modules/juce_core/misc/juce_Uuid.cpp"
    "../../../../../JUCE/modules/juce_core/misc/juce_Uuid.h"
    "../../../../../JUCE/modules/juce_core/misc/juce_WindowsRegistry.h"
    "../../../../../JUCE/modules/juce_core/native/java/README.txt"
    "../../../../../JUCE/modules/juce_core/native/juce_android_Files.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_android_JNIHelpers.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_android_JNIHelpers.h"
    "../../../../../JUCE/modules/juce_core/native/juce_android_Misc.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_android_Network.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_android_RuntimePermissions.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_android_SystemStats.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_android_Threads.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_BasicNativeHeaders.h"
    "../../../../../JUCE/modules/juce_core/native/juce_curl_Network.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_linux_CommonFile.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_linux_Files.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_linux_Network.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_linux_SystemStats.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_linux_Threads.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_mac_ClangBugWorkaround.h"
    "../../../../../JUCE/modules/juce_core/native/juce_mac_Files.mm"
    "../../../../../JUCE/modules/juce_core/native/juce_mac_Network.mm"
    "../../../../../JUCE/modules/juce_core/native/juce_mac_Strings.mm"
    "../../../../../JUCE/modules/juce_core/native/juce_mac_SystemStats.mm"
    "../../../../../JUCE/modules/juce_core/native/juce_mac_Threads.mm"
    "../../../../../JUCE/modules/juce_core/native/juce_osx_ObjCHelpers.h"
    "../../../../../JUCE/modules/juce_core/native/juce_posix_IPAddress.h"
    "../../../../../JUCE/modules/juce_core/native/juce_posix_NamedPipe.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_posix_SharedCode.h"
    "../../../../../JUCE/modules/juce_core/native/juce_win32_ComSmartPtr.h"
    "../../../../../JUCE/modules/juce_core/native/juce_win32_Files.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_win32_Network.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_win32_Registry.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_win32_SystemStats.cpp"
    "../../../../../JUCE/modules/juce_core/native/juce_win32_Threads.cpp"
    "../../../../../JUCE/modules/juce_core/network/juce_IPAddress.cpp"
    "../../../../../JUCE/modules/juce_core/network/juce_IPAddress.h"
    "../../../../../JUCE/modules/juce_core/network/juce_MACAddress.cpp"
    "../../../../../JUCE/modules/juce_core/network/juce_MACAddress.h"
    "../../../../../JUCE/modules/juce_core/network/juce_NamedPipe.cpp"
    "../../../../../JUCE/modules/juce_core/network/juce_NamedPipe.h"
    "../../../../../JUCE/modules/juce_core/network/juce_Socket.cpp"
    "../../../../../JUCE/modules/juce_core/network/juce_Socket.h"
    "../../../../../JUCE/modules/juce_core/network/juce_URL.cpp"
    "../../../../../JUCE/modules/juce_core/network/juce_URL.h"
    "../../../../../JUCE/modules/juce_core/network/juce_WebInputStream.cpp"
    "../../../../../JUCE/modules/juce_core/network/juce_WebInputStream.h"
    "../../../../../JUCE/modules/juce_core/streams/juce_BufferedInputStream.cpp"
    "../../../../../JUCE/modules/juce_core/streams/juce_BufferedInputStream.h"
    "../../../../../JUCE/modules/juce_core/streams/juce_FileInputSource.cpp"
    "../../../../../JUCE/modules/juce_core/streams/juce_FileInputSource.h"
    "../../../../../JUCE/modules/juce_core/streams/juce_InputSource.h"
    "../../../../../JUCE/modules/juce_core/streams/juce_InputStream.cpp"
    "../../../../../JUCE/modules/juce_core/streams/juce_InputStream.h"
    "../../../../../JUCE/modules/juce_core/streams/juce_MemoryInputStream.cpp"
    "../../../../../JUCE/modules/juce_core/streams/juce_MemoryInputStream.h"
    "../../../../../JUCE/modules/juce_core/streams/juce_MemoryOutputStream.cpp"
    "../../../../../JUCE/modules/juce_core/streams/juce_MemoryOutputStream.h"
    "../../../../../JUCE/modules/juce_core/streams/juce_OutputStream.cpp"
    "../../../../../JUCE/modules/juce_core/streams/juce_OutputStream.h"
    "../../../../../JUCE/modules/juce_core/streams/juce_SubregionStream.cpp"
    "../../../../../JUCE/modules/juce_core/streams/juce_SubregionStream.h"
    "../../../../../JUCE/modules/juce_core/streams/juce_URLInputSource.cpp"
    "../../../../../JUCE/modules/juce_core/streams/juce_URLInputSource.h"
    "../../../../../JUCE/modules/juce_core/system/juce_CompilerSupport.h"
    "../../../../../JUCE/modules/juce_core/system/juce_PlatformDefs.h"
    "../../../../../JUCE/modules/juce_core/system/juce_StandardHeader.h"
    "../../../../../JUCE/modules/juce_core/system/juce_SystemStats.cpp"
    "../../../../../JUCE/modules/juce_core/system/juce_SystemStats.h"
    "../../../../../JUCE/modules/juce_core/system/juce_TargetPlatform.h"
    "../../../../../JUCE/modules/juce_core/text/juce_Base64.cpp"
    "../../../../../JUCE/modules/juce_core/text/juce_Base64.h"
    "../../../../../JUCE/modules/juce_core/text/juce_CharacterFunctions.cpp"
    "../../../../../JUCE/modules/juce_core/text/juce_CharacterFunctions.h"
    "../../../../../JUCE/modules/juce_core/text/juce_CharPointer_ASCII.h"
    "../../../../../JUCE/modules/juce_core/text/juce_CharPointer_UTF8.h"
    "../../../../../JUCE/modules/juce_core/text/juce_CharPointer_UTF16.h"
    "../../../../../JUCE/modules/juce_core/text/juce_CharPointer_UTF32.h"
    "../../../../../JUCE/modules/juce_core/text/juce_Identifier.cpp"
    "../../../../../JUCE/modules/juce_core/text/juce_Identifier.h"
    "../../../../../JUCE/modules/juce_core/text/juce_LocalisedStrings.cpp"
    "../../../../../JUCE/modules/juce_core/text/juce_LocalisedStrings.h"
    "../../../../../JUCE/modules/juce_core/text/juce_NewLine.h"
    "../../../../../JUCE/modules/juce_core/text/juce_String.cpp"
    "../../../../../JUCE/modules/juce_core/text/juce_String.h"
    "../../../../../JUCE/modules/juce_core/text/juce_StringArray.cpp"
    "../../../../../JUCE/modules/juce_core/text/juce_StringArray.h"
    "../../../../../JUCE/modules/juce_core/text/juce_StringPairArray.cpp"
    "../../../../../JUCE/modules/juce_core/text/juce_StringPairArray.h"
    "../../../../../JUCE/modules/juce_core/text/juce_StringPool.cpp"
    "../../../../../JUCE/modules/juce_core/text/juce_StringPool.h"
    "../../../../../JUCE/modules/juce_core/text/juce_StringRef.h"
    "../../../../../JUCE/modules/juce_core/text/juce_TextDiff.cpp"
    "../../../../../JUCE/modules/juce_core/text/juce_TextDiff.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_ChildProcess.cpp"
    "../../../../../JUCE/modules/juce_core/threads/juce_ChildProcess.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_CriticalSection.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_DynamicLibrary.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_HighResolutionTimer.cpp"
    "../../../../../JUCE/modules/juce_core/threads/juce_HighResolutionTimer.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_InterProcessLock.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_Process.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_ReadWriteLock.cpp"
    "../../../../../JUCE/modules/juce_core/threads/juce_ReadWriteLock.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_ScopedLock.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_ScopedReadLock.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_ScopedWriteLock.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_SpinLock.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_Thread.cpp"
    "../../../../../JUCE/modules/juce_core/threads/juce_Thread.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_ThreadLocalValue.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_ThreadPool.cpp"
    "../../../../../JUCE/modules/juce_core/threads/juce_ThreadPool.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_TimeSliceThread.cpp"
    "../../../../../JUCE/modules/juce_core/threads/juce_TimeSliceThread.h"
    "../../../../../JUCE/modules/juce_core/threads/juce_WaitableEvent.h"
    "../../../../../JUCE/modules/juce_core/time/juce_PerformanceCounter.cpp"
    "../../../../../JUCE/modules/juce_core/time/juce_PerformanceCounter.h"
    "../../../../../JUCE/modules/juce_core/time/juce_RelativeTime.cpp"
    "../../../../../JUCE/modules/juce_core/time/juce_RelativeTime.h"
    "../../../../../JUCE/modules/juce_core/time/juce_Time.cpp"
    "../../../../../JUCE/modules/juce_core/time/juce_Time.h"
    "../../../../../JUCE/modules/juce_core/unit_tests/juce_UnitTest.cpp"
    "../../../../../JUCE/modules/juce_core/unit_tests/juce_UnitTest.h"
    "../../../../../JUCE/modules/juce_core/xml/juce_XmlDocument.cpp"
    "../../../../../JUCE/modules/juce_core/xml/juce_XmlDocument.h"
    "../../../../../JUCE/modules/juce_core/xml/juce_XmlElement.cpp"
    "../../../../../JUCE/modules/juce_core/xml/juce_XmlElement.h"
    "../../../../../JUCE/modules/juce_core/zip/zlib/adler32.c"
    "../../../../../JUCE/modules/juce_core/zip/zlib/compress.c"
    "../../../../../JUCE/modules/juce_core/zip/zlib/crc32.c"
    "../../../../../JUCE/modules/juce_core/zip/zlib/crc32.h"
    "../../../../../JUCE/modules/juce_core/zip/zlib/deflate.c"
    "../../../../../JUCE/modules/juce_core/zip/zlib/deflate.h"
    "../../../../../JUCE/modules/juce_core/zip/zlib/infback.c"
    "../../../../../JUCE/modules/juce_core/zip/zlib/inffast.c"
    "../../../../../JUCE/modules/juce_core/zip/zlib/inffast.h"
    "../../../../../JUCE/modules/juce_core/zip/zlib/inffixed.h"
    "../../../../../JUCE/modules/juce_core/zip/zlib/inflate.c"
    "../../../../../JUCE/modules/juce_core/zip/zlib/inflate.h"
    "../../../../../JUCE/modules/juce_core/zip/zlib/inftrees.c"
    "../../../../../JUCE/modules/juce_core/zip/zlib/inftrees.h"
    "../../../../../JUCE/modules/juce_core/zip/zlib/trees.c"
    "../../../../../JUCE/modules/juce_core/zip/zlib/trees.h"
    "../../../../../JUCE/modules/juce_core/zip/zlib/uncompr.c"
    "../../../../../JUCE/modules/juce_core/zip/zlib/zconf.h"
    "../../../../../JUCE/modules/juce_core/zip/zlib/zconf.in.h"
    "../../../../../JUCE/modules/juce_core/zip/zlib/zlib.h"
    "../../../../../JUCE/modules/juce_core/zip/zlib/zutil.c"
    "../../../../../JUCE/modules/juce_core/zip/zlib/zutil.h"
    "../../../../../JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.cpp"
    "../../../../../JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.h"
    "../../../../../JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.cpp"
    "../../../../../JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.h"
    "../../../../../JUCE/modules/juce_core/zip/juce_ZipFile.cpp"
    "../../../../../JUCE/modules/juce_core/zip/juce_ZipFile.h"
    "../../../../../JUCE/modules/juce_core/juce_core.cpp"
    "../../../../../JUCE/modules/juce_core/juce_core.mm"
    "../../../../../JUCE/modules/juce_core/juce_core.h"
    "../../../../../JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.cpp"
    "../../../../../JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.h"
    "../../../../../JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp"
    "../../../../../JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.h"
    "../../../../../JUCE/modules/juce_data_structures/undomanager/juce_UndoableAction.h"
    "../../../../../JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.cpp"
    "../../../../../JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.h"
    "../../../../../JUCE/modules/juce_data_structures/values/juce_CachedValue.cpp"
    "../../../../../JUCE/modules/juce_data_structures/values/juce_CachedValue.h"
    "../../../../../JUCE/modules/juce_data_structures/values/juce_Value.cpp"
    "../../../../../JUCE/modules/juce_data_structures/values/juce_Value.h"
    "../../../../../JUCE/modules/juce_data_structures/values/juce_ValueTree.cpp"
    "../../../../../JUCE/modules/juce_data_structures/values/juce_ValueTree.h"
    "../../../../../JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp"
    "../../../../../JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.h"
    "../../../../../JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.cpp"
    "../../../../../JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.h"
    "../../../../../JUCE/modules/juce_data_structures/juce_data_structures.cpp"
    "../../../../../JUCE/modules/juce_data_structures/juce_data_structures.mm"
    "../../../../../JUCE/modules/juce_data_structures/juce_data_structures.h"
    "../../../../../JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.cpp"
    "../../../../../JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.h"
    "../../../../../JUCE/modules/juce_events/broadcasters/juce_ActionListener.h"
    "../../../../../JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.cpp"
    "../../../../../JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.h"
    "../../../../../JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.cpp"
    "../../../../../JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.h"
    "../../../../../JUCE/modules/juce_events/broadcasters/juce_ChangeListener.h"
    "../../../../../JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.cpp"
    "../../../../../JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.h"
    "../../../../../JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.cpp"
    "../../../../../JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.h"
    "../../../../../JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.cpp"
    "../../../../../JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.h"
    "../../../../../JUCE/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.cpp"
    "../../../../../JUCE/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.h"
    "../../../../../JUCE/modules/juce_events/messages/juce_ApplicationBase.cpp"
    "../../../../../JUCE/modules/juce_events/messages/juce_ApplicationBase.h"
    "../../../../../JUCE/modules/juce_events/messages/juce_CallbackMessage.h"
    "../../../../../JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.cpp"
    "../../../../../JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.h"
    "../../../../../JUCE/modules/juce_events/messages/juce_Initialisation.h"
    "../../../../../JUCE/modules/juce_events/messages/juce_Message.h"
    "../../../../../JUCE/modules/juce_events/messages/juce_MessageListener.cpp"
    "../../../../../JUCE/modules/juce_events/messages/juce_MessageListener.h"
    "../../../../../JUCE/modules/juce_events/messages/juce_MessageManager.cpp"
    "../../../../../JUCE/modules/juce_events/messages/juce_MessageManager.h"
    "../../../../../JUCE/modules/juce_events/messages/juce_MountedVolumeListChangeDetector.h"
    "../../../../../JUCE/modules/juce_events/messages/juce_NotificationType.h"
    "../../../../../JUCE/modules/juce_events/native/juce_android_Messaging.cpp"
    "../../../../../JUCE/modules/juce_events/native/juce_ios_MessageManager.mm"
    "../../../../../JUCE/modules/juce_events/native/juce_linux_EventLoop.h"
    "../../../../../JUCE/modules/juce_events/native/juce_linux_Messaging.cpp"
    "../../../../../JUCE/modules/juce_events/native/juce_mac_MessageManager.mm"
    "../../../../../JUCE/modules/juce_events/native/juce_osx_MessageQueue.h"
    "../../../../../JUCE/modules/juce_events/native/juce_win32_HiddenMessageWindow.h"
    "../../../../../JUCE/modules/juce_events/native/juce_win32_Messaging.cpp"
    "../../../../../JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.cpp"
    "../../../../../JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.h"
    "../../../../../JUCE/modules/juce_events/timers/juce_MultiTimer.cpp"
    "../../../../../JUCE/modules/juce_events/timers/juce_MultiTimer.h"
    "../../../../../JUCE/modules/juce_events/timers/juce_Timer.cpp"
    "../../../../../JUCE/modules/juce_events/timers/juce_Timer.h"
    "../../../../../JUCE/modules/juce_events/juce_events.cpp"
    "../../../../../JUCE/modules/juce_events/juce_events.mm"
    "../../../../../JUCE/modules/juce_events/juce_events.h"
    "../../../../../JUCE/modules/juce_graphics/colour/juce_Colour.cpp"
    "../../../../../JUCE/modules/juce_graphics/colour/juce_Colour.h"
    "../../../../../JUCE/modules/juce_graphics/colour/juce_ColourGradient.cpp"
    "../../../../../JUCE/modules/juce_graphics/colour/juce_ColourGradient.h"
    "../../../../../JUCE/modules/juce_graphics/colour/juce_Colours.cpp"
    "../../../../../JUCE/modules/juce_graphics/colour/juce_Colours.h"
    "../../../../../JUCE/modules/juce_graphics/colour/juce_FillType.cpp"
    "../../../../../JUCE/modules/juce_graphics/colour/juce_FillType.h"
    "../../../../../JUCE/modules/juce_graphics/colour/juce_PixelFormats.h"
    "../../../../../JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.cpp"
    "../../../../../JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.h"
    "../../../../../JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsContext.h"
    "../../../../../JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp"
    "../../../../../JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h"
    "../../../../../JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp"
    "../../../../../JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h"
    "../../../../../JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.cpp"
    "../../../../../JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.h"
    "../../../../../JUCE/modules/juce_graphics/effects/juce_GlowEffect.cpp"
    "../../../../../JUCE/modules/juce_graphics/effects/juce_GlowEffect.h"
    "../../../../../JUCE/modules/juce_graphics/effects/juce_ImageEffectFilter.h"
    "../../../../../JUCE/modules/juce_graphics/fonts/juce_AttributedString.cpp"
    "../../../../../JUCE/modules/juce_graphics/fonts/juce_AttributedString.h"
    "../../../../../JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.cpp"
    "../../../../../JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.h"
    "../../../../../JUCE/modules/juce_graphics/fonts/juce_Font.cpp"
    "../../../../../JUCE/modules/juce_graphics/fonts/juce_Font.h"
    "../../../../../JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.cpp"
    "../../../../../JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.h"
    "../../../../../JUCE/modules/juce_graphics/fonts/juce_TextLayout.cpp"
    "../../../../../JUCE/modules/juce_graphics/fonts/juce_TextLayout.h"
    "../../../../../JUCE/modules/juce_graphics/fonts/juce_Typeface.cpp"
    "../../../../../JUCE/modules/juce_graphics/fonts/juce_Typeface.h"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_AffineTransform.cpp"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_AffineTransform.h"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_BorderSize.h"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_EdgeTable.cpp"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_EdgeTable.h"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_Line.h"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_Parallelogram.h"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_Path.cpp"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_Path.h"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_PathIterator.cpp"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_PathIterator.h"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.cpp"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.h"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_Point.h"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_Rectangle.h"
    "../../../../../JUCE/modules/juce_graphics/geometry/juce_RectangleList.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/cderror.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcapimin.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcapistd.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jccoefct.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jccolor.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcdctmgr.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcinit.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcmainct.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcmarker.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcmaster.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcomapi.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jconfig.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcparam.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcphuff.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcprepct.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcsample.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jctrans.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdapimin.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdapistd.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdatasrc.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdcoefct.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdcolor.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdct.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jddctmgr.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdinput.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdmainct.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdmarker.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdmaster.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdmerge.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdphuff.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdpostct.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdsample.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdtrans.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jerror.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jerror.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jfdctflt.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jfdctfst.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jfdctint.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jidctflt.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jidctfst.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jidctint.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jidctred.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jinclude.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jmemmgr.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jmemnobs.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jmemsys.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jmorecfg.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jpegint.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jpeglib.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jquant1.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jquant2.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jutils.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jversion.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/transupp.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/transupp.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/libpng_readme.txt"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/png.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/png.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngconf.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngerror.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngget.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pnginfo.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngmem.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngpread.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngpriv.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngread.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngrio.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngrtran.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngrutil.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngset.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngstruct.h"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngtrans.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngwio.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngwrite.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngwtran.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngwutil.c"
    "../../../../../JUCE/modules/juce_graphics/image_formats/juce_GIFLoader.cpp"
    "../../../../../JUCE/modules/juce_graphics/image_formats/juce_JPEGLoader.cpp"
    "../../../../../JUCE/modules/juce_graphics/image_formats/juce_PNGLoader.cpp"
    "../../../../../JUCE/modules/juce_graphics/images/juce_Image.cpp"
    "../../../../../JUCE/modules/juce_graphics/images/juce_Image.h"
    "../../../../../JUCE/modules/juce_graphics/images/juce_ImageCache.cpp"
    "../../../../../JUCE/modules/juce_graphics/images/juce_ImageCache.h"
    "../../../../../JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.cpp"
    "../../../../../JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.h"
    "../../../../../JUCE/modules/juce_graphics/images/juce_ImageFileFormat.cpp"
    "../../../../../JUCE/modules/juce_graphics/images/juce_ImageFileFormat.h"
    "../../../../../JUCE/modules/juce_graphics/native/juce_android_Fonts.cpp"
    "../../../../../JUCE/modules/juce_graphics/native/juce_android_GraphicsContext.cpp"
    "../../../../../JUCE/modules/juce_graphics/native/juce_android_IconHelpers.cpp"
    "../../../../../JUCE/modules/juce_graphics/native/juce_freetype_Fonts.cpp"
    "../../../../../JUCE/modules/juce_graphics/native/juce_linux_Fonts.cpp"
    "../../../../../JUCE/modules/juce_graphics/native/juce_linux_IconHelpers.cpp"
    "../../../../../JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.h"
    "../../../../../JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.mm"
    "../../../../../JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h"
    "../../../../../JUCE/modules/juce_graphics/native/juce_mac_Fonts.mm"
    "../../../../../JUCE/modules/juce_graphics/native/juce_mac_IconHelpers.cpp"
    "../../../../../JUCE/modules/juce_graphics/native/juce_RenderingHelpers.h"
    "../../../../../JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp"
    "../../../../../JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h"
    "../../../../../JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp"
    "../../../../../JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp"
    "../../../../../JUCE/modules/juce_graphics/native/juce_win32_Fonts.cpp"
    "../../../../../JUCE/modules/juce_graphics/native/juce_win32_IconHelpers.cpp"
    "../../../../../JUCE/modules/juce_graphics/placement/juce_Justification.h"
    "../../../../../JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.cpp"
    "../../../../../JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.h"
    "../../../../../JUCE/modules/juce_graphics/juce_graphics.cpp"
    "../../../../../JUCE/modules/juce_graphics/juce_graphics.mm"
    "../../../../../JUCE/modules/juce_graphics/juce_graphics.h"
    "../../../../../JUCE/modules/juce_gui_basics/application/juce_Application.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/application/juce_Application.h"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.h"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_Button.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_Button.h"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.h"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.h"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.h"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.h"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_TextButton.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_TextButton.h"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.h"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.h"
    "../../../../../JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandID.h"
    "../../../../../JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.h"
    "../../../../../JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.h"
    "../../../../../JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.h"
    "../../../../../JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.h"
    "../../../../../JUCE/modules/juce_gui_basics/components/juce_CachedComponentImage.h"
    "../../../../../JUCE/modules/juce_gui_basics/components/juce_Component.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/components/juce_Component.h"
    "../../../../../JUCE/modules/juce_gui_basics/components/juce_ComponentListener.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/components/juce_ComponentListener.h"
    "../../../../../JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.h"
    "../../../../../JUCE/modules/juce_gui_basics/desktop/juce_Desktop.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/desktop/juce_Desktop.h"
    "../../../../../JUCE/modules/juce_gui_basics/desktop/juce_Displays.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/desktop/juce_Displays.h"
    "../../../../../JUCE/modules/juce_gui_basics/drawables/juce_Drawable.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/drawables/juce_Drawable.h"
    "../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.h"
    "../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.h"
    "../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.h"
    "../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.h"
    "../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.h"
    "../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.h"
    "../../../../../JUCE/modules/juce_gui_basics/drawables/juce_SVGParser.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.h"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserListener.h"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.h"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h"
    "../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.h"
    "../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.h"
    "../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.h"
    "../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_SystemClipboard.h"
    "../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h"
    "../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_TextInputTarget.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_AnimatedPosition.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_FlexBox.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_FlexBox.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_FlexItem.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_Grid.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_Grid.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_GridItem.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_GridItem.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_GridUnitTests.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_SidePanel.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_SidePanel.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_Viewport.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/layout/juce_Viewport.h"
    "../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.h"
    "../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h"
    "../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h"
    "../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h"
    "../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h"
    "../../../../../JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.h"
    "../../../../../JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.h"
    "../../../../../JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/misc/juce_DropShadower.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/misc/juce_DropShadower.h"
    "../../../../../JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.h"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.h"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.h"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropTarget.h"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_LassoComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.h"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.h"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.h"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.h"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.h"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_SelectedItemSet.h"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h"
    "../../../../../JUCE/modules/juce_gui_basics/mouse/juce_TooltipClient.h"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_android_ContentSharer.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_android_FileChooser.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_android_Windowing.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_common_MimeTypes.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_ios_ContentSharer.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_ios_FileChooser.mm"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_ios_Windowing.mm"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_linux_FileChooser.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_linux_X11.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_linux_X11.h"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_linux_X11_Clipboard.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_linux_X11_Windowing.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_mac_FileChooser.mm"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_mac_MainMenu.mm"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_mac_MouseCursor.mm"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_mac_Windowing.mm"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_MultiTouchMapper.h"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_win32_DragAndDrop.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_win32_FileChooser.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/native/juce_win32_Windowing.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.h"
    "../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.h"
    "../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h"
    "../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.h"
    "../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.h"
    "../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.h"
    "../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.h"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.h"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.h"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_Label.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_Label.h"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ListBox.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ListBox.h"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.h"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_Slider.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_Slider.h"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.h"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.h"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.h"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.h"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemFactory.h"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.h"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TreeView.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TreeView.h"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.h"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.h"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.h"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.h"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.h"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_NativeMessageBox.h"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.h"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.h"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.h"
    "../../../../../JUCE/modules/juce_gui_basics/juce_gui_basics.cpp"
    "../../../../../JUCE/modules/juce_gui_basics/juce_gui_basics.mm"
    "../../../../../JUCE/modules/juce_gui_basics/juce_gui_basics.h"
    "../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.h"
    "../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.h"
    "../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CodeTokeniser.h"
    "../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.h"
    "../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniserFunctions.h"
    "../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.h"
    "../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.h"
    "../../../../../JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.h"
    "../../../../../JUCE/modules/juce_gui_extra/embedding/juce_ActiveXControlComponent.h"
    "../../../../../JUCE/modules/juce_gui_extra/embedding/juce_AndroidViewComponent.h"
    "../../../../../JUCE/modules/juce_gui_extra/embedding/juce_NSViewComponent.h"
    "../../../../../JUCE/modules/juce_gui_extra/embedding/juce_ScopedDPIAwarenessDisabler.h"
    "../../../../../JUCE/modules/juce_gui_extra/embedding/juce_UIViewComponent.h"
    "../../../../../JUCE/modules/juce_gui_extra/embedding/juce_XEmbedComponent.h"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.h"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_AppleRemote.h"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.h"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.h"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.h"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.h"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.h"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.h"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.h"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.h"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.h"
    "../../../../../JUCE/modules/juce_gui_extra/misc/juce_WebBrowserComponent.h"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_android_PushNotifications.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_android_WebBrowserComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_AndroidViewComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_ios_PushNotifications.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_ios_UIViewComponent.mm"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_linux_X11_SystemTrayIcon.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_linux_X11_WebBrowserComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_linux_XEmbedComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_mac_AppleRemote.mm"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_mac_CarbonViewWrapperComponent.h"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_mac_NSViewComponent.mm"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_mac_PushNotifications.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_mac_SystemTrayIcon.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_mac_WebBrowserComponent.mm"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_win32_ActiveXComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_win32_SystemTrayIcon.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/native/juce_win32_WebBrowserComponent.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/juce_gui_extra.cpp"
    "../../../../../JUCE/modules/juce_gui_extra/juce_gui_extra.mm"
    "../../../../../JUCE/modules/juce_gui_extra/juce_gui_extra.h"
    "../../../../../JUCE/modules/juce_opengl/geometry/juce_Draggable3DOrientation.h"
    "../../../../../JUCE/modules/juce_opengl/geometry/juce_Matrix3D.h"
    "../../../../../JUCE/modules/juce_opengl/geometry/juce_Quaternion.h"
    "../../../../../JUCE/modules/juce_opengl/geometry/juce_Vector3D.h"
    "../../../../../JUCE/modules/juce_opengl/native/juce_MissingGLDefinitions.h"
    "../../../../../JUCE/modules/juce_opengl/native/juce_OpenGL_android.h"
    "../../../../../JUCE/modules/juce_opengl/native/juce_OpenGL_ios.h"
    "../../../../../JUCE/modules/juce_opengl/native/juce_OpenGL_linux_X11.h"
    "../../../../../JUCE/modules/juce_opengl/native/juce_OpenGL_osx.h"
    "../../../../../JUCE/modules/juce_opengl/native/juce_OpenGL_win32.h"
    "../../../../../JUCE/modules/juce_opengl/native/juce_OpenGLExtensions.h"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.cpp"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.h"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.cpp"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.h"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.cpp"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.h"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.cpp"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.h"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.cpp"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.h"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.cpp"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.h"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLRenderer.h"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.cpp"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.h"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.cpp"
    "../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.h"
    "../../../../../JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.cpp"
    "../../../../../JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.h"
    "../../../../../JUCE/modules/juce_opengl/juce_opengl.cpp"
    "../../../../../JUCE/modules/juce_opengl/juce_opengl.mm"
    "../../../../../JUCE/modules/juce_opengl/juce_opengl.h"
    "../../../JuceLibraryCode/AppConfig.h"
    "../../../JuceLibraryCode/include_juce_core.cpp"
    "../../../JuceLibraryCode/include_juce_data_structures.cpp"
    "../../../JuceLibraryCode/include_juce_events.cpp"
    "../../../JuceLibraryCode/include_juce_graphics.cpp"
    "../../../JuceLibraryCode/include_juce_gui_basics.cpp"
    "../../../JuceLibraryCode/include_juce_gui_extra.cpp"
    "../../../JuceLibraryCode/include_juce_opengl.cpp"
    "../../../JuceLibraryCode/JuceHeader.h"
)

set_source_files_properties("../../../Source/DensePixelShape.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/SystemHeapStack.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/DSU.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/Triple.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/Menu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/PointsToDraw.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/Color.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/Shape.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/PixelShape.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/GreatColor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/CustomTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/MazeGenerator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/OpenGLDrawer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/Pair.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/Application.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/CentralComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../Source/MainForm.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_AbstractFifo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_AbstractFifo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_Array.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_ArrayAllocationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_ArrayBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_ArrayBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_DynamicObject.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_DynamicObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_ElementComparator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_HashMap.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_HashMap_test.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_LinkedListPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_ListenerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_NamedValueSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_NamedValueSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_OwnedArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_OwnedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_PropertySet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_PropertySet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_ReferenceCountedArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_ScopedValueSetter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_SortedSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_SparseSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_SparseSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_Variant.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/containers/juce_Variant.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_DirectoryIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_DirectoryIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_File.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_File.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_FileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_FileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_FileInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_FileInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_FileOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_FileOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_FileSearchPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_FileSearchPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_MemoryMappedFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_TemporaryFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_TemporaryFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_WildcardFileFilter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/files/juce_WildcardFileFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/javascript/juce_Javascript.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/javascript/juce_Javascript.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/javascript/juce_JSON.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/javascript/juce_JSON.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/logging/juce_FileLogger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/logging/juce_FileLogger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/logging/juce_Logger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/logging/juce_Logger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/maths/juce_BigInteger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/maths/juce_BigInteger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/maths/juce_Expression.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/maths/juce_Expression.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/maths/juce_MathsFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/maths/juce_NormalisableRange.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/maths/juce_Random.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/maths/juce_Random.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/maths/juce_Range.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/maths/juce_StatisticsAccumulator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/memory/juce_Atomic.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/memory/juce_ByteOrder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/memory/juce_ContainerDeletePolicy.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/memory/juce_HeapBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/memory/juce_HeavyweightLeakedObjectDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/memory/juce_LeakedObjectDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/memory/juce_Memory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/memory/juce_MemoryBlock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/memory/juce_MemoryBlock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/memory/juce_OptionalScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/memory/juce_ReferenceCountedObject.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/memory/juce_ScopedPointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/memory/juce_SharedResourcePointer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/memory/juce_Singleton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/memory/juce_WeakReference.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/misc/juce_ConsoleApplication.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/misc/juce_ConsoleApplication.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/misc/juce_Result.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/misc/juce_Result.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/misc/juce_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/misc/juce_RuntimePermissions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/misc/juce_StdFunctionCompat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/misc/juce_StdFunctionCompat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/misc/juce_Uuid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/misc/juce_Uuid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/misc/juce_WindowsRegistry.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/java/README.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_android_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_android_JNIHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_android_JNIHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_android_Misc.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_android_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_android_RuntimePermissions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_android_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_android_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_BasicNativeHeaders.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_curl_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_linux_CommonFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_linux_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_linux_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_linux_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_linux_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_mac_ClangBugWorkaround.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_mac_Files.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_mac_Network.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_mac_Strings.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_mac_SystemStats.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_mac_Threads.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_osx_ObjCHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_posix_IPAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_posix_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_posix_SharedCode.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_win32_ComSmartPtr.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_win32_Files.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_win32_Network.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_win32_Registry.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_win32_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/native/juce_win32_Threads.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/network/juce_IPAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/network/juce_IPAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/network/juce_MACAddress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/network/juce_MACAddress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/network/juce_NamedPipe.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/network/juce_NamedPipe.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/network/juce_Socket.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/network/juce_Socket.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/network/juce_URL.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/network/juce_URL.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/network/juce_WebInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/network/juce_WebInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_BufferedInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_BufferedInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_FileInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_FileInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_InputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_InputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_InputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_MemoryInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_MemoryInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_MemoryOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_MemoryOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_OutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_OutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_SubregionStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_SubregionStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_URLInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/streams/juce_URLInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/system/juce_CompilerSupport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/system/juce_PlatformDefs.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/system/juce_StandardHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/system/juce_SystemStats.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/system/juce_SystemStats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/system/juce_TargetPlatform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_Base64.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_Base64.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_CharacterFunctions.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_CharacterFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_CharPointer_ASCII.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_CharPointer_UTF8.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_CharPointer_UTF16.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_CharPointer_UTF32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_Identifier.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_Identifier.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_LocalisedStrings.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_LocalisedStrings.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_NewLine.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_String.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_String.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_StringArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_StringArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_StringPairArray.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_StringPairArray.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_StringPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_StringPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_StringRef.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_TextDiff.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/text/juce_TextDiff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_ChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_ChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_CriticalSection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_DynamicLibrary.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_HighResolutionTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_HighResolutionTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_InterProcessLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_Process.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_ReadWriteLock.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_ReadWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_ScopedLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_ScopedReadLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_ScopedWriteLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_SpinLock.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_Thread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_Thread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_ThreadLocalValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_ThreadPool.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_ThreadPool.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_TimeSliceThread.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_TimeSliceThread.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/threads/juce_WaitableEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/time/juce_PerformanceCounter.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/time/juce_PerformanceCounter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/time/juce_RelativeTime.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/time/juce_RelativeTime.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/time/juce_Time.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/time/juce_Time.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/unit_tests/juce_UnitTest.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/unit_tests/juce_UnitTest.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/xml/juce_XmlDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/xml/juce_XmlDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/xml/juce_XmlElement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/xml/juce_XmlElement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/adler32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/compress.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/crc32.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/crc32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/deflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/deflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/infback.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/inffast.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/inffast.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/inffixed.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/inflate.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/inflate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/inftrees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/inftrees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/trees.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/trees.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/uncompr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/zconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/zconf.in.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/zlib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/zutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/zlib/zutil.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/juce_GZIPCompressorOutputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/juce_GZIPDecompressorInputStream.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/juce_ZipFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/zip/juce_ZipFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/juce_core.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/juce_core.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_core/juce_core.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/app_properties/juce_ApplicationProperties.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/app_properties/juce_PropertiesFile.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/undomanager/juce_UndoableAction.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/undomanager/juce_UndoManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/values/juce_CachedValue.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/values/juce_CachedValue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/values/juce_Value.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/values/juce_Value.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/values/juce_ValueTree.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/values/juce_ValueTree.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/values/juce_ValueTreeSynchroniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/values/juce_ValueWithDefault.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/juce_data_structures.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/juce_data_structures.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_data_structures/juce_data_structures.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/broadcasters/juce_ActionBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/broadcasters/juce_ActionListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/broadcasters/juce_AsyncUpdater.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/broadcasters/juce_ChangeBroadcaster.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/broadcasters/juce_ChangeListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/interprocess/juce_ConnectedChildProcess.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/interprocess/juce_InterprocessConnection.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/interprocess/juce_InterprocessConnectionServer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/interprocess/juce_NetworkServiceDiscovery.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/messages/juce_ApplicationBase.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/messages/juce_ApplicationBase.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/messages/juce_CallbackMessage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/messages/juce_DeletedAtShutdown.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/messages/juce_Initialisation.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/messages/juce_Message.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/messages/juce_MessageListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/messages/juce_MessageListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/messages/juce_MessageManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/messages/juce_MessageManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/messages/juce_MountedVolumeListChangeDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/messages/juce_NotificationType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/native/juce_android_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/native/juce_ios_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/native/juce_linux_EventLoop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/native/juce_linux_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/native/juce_mac_MessageManager.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/native/juce_osx_MessageQueue.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/native/juce_win32_HiddenMessageWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/native/juce_win32_Messaging.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/native/juce_win32_WinRTWrapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/timers/juce_MultiTimer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/timers/juce_MultiTimer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/timers/juce_Timer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/timers/juce_Timer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/juce_events.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/juce_events.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_events/juce_events.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/colour/juce_Colour.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/colour/juce_Colour.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/colour/juce_ColourGradient.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/colour/juce_ColourGradient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/colour/juce_Colours.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/colour/juce_Colours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/colour/juce_FillType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/colour/juce_FillType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/colour/juce_PixelFormats.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/contexts/juce_GraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsPostScriptRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/contexts/juce_LowLevelGraphicsSoftwareRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/effects/juce_DropShadowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/effects/juce_GlowEffect.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/effects/juce_GlowEffect.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/effects/juce_ImageEffectFilter.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/fonts/juce_AttributedString.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/fonts/juce_AttributedString.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/fonts/juce_CustomTypeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/fonts/juce_Font.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/fonts/juce_Font.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/fonts/juce_GlyphArrangement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/fonts/juce_TextLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/fonts/juce_TextLayout.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/fonts/juce_Typeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/fonts/juce_Typeface.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_AffineTransform.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_AffineTransform.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_BorderSize.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_EdgeTable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_EdgeTable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_Line.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_Parallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_Path.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_Path.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_PathIterator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_PathIterator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_PathStrokeType.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_Point.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_Rectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/geometry/juce_RectangleList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/cderror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/changes to libjpeg for JUCE.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jccoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jccolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcdctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jchuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcinit.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcomapi.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jconfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcparam.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcprepct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jcsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jctrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdapimin.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdapistd.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdatasrc.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdcoefct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdcolor.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jddctmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdhuff.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdinput.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdmainct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdmarker.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdmaster.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdmerge.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdphuff.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdpostct.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdsample.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jdtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jerror.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jfdctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jfdctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jfdctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jidctflt.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jidctfst.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jidctint.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jidctred.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jinclude.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jmemmgr.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jmemnobs.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jmemsys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jmorecfg.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jpegint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jpeglib.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jquant1.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jquant2.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jutils.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/jversion.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/transupp.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/jpglib/transupp.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/libpng_readme.txt" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/png.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/png.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngconf.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngerror.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngget.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pnginfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngmem.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngpread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngpriv.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngread.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngrio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngrtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngrutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngset.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngstruct.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngtrans.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngwio.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngwrite.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngwtran.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/pnglib/pngwutil.c" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/juce_GIFLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/juce_JPEGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/image_formats/juce_PNGLoader.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/images/juce_Image.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/images/juce_Image.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/images/juce_ImageCache.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/images/juce_ImageCache.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/images/juce_ImageConvolutionKernel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/images/juce_ImageFileFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/images/juce_ImageFileFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_android_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_android_GraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_android_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_freetype_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_linux_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_linux_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsContext.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_mac_CoreGraphicsHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_mac_Fonts.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_mac_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_RenderingHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_win32_Direct2DGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeface.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_win32_DirectWriteTypeLayout.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_win32_Fonts.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/native/juce_win32_IconHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/placement/juce_Justification.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/placement/juce_RectanglePlacement.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/juce_graphics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/juce_graphics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_graphics/juce_graphics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/application/juce_Application.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/application/juce_Application.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ArrowButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_Button.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_Button.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_DrawableButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_HyperlinkButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ImageButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ShapeButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_TextButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_TextButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ToggleButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/buttons/juce_ToolbarButton.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandID.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandInfo.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/commands/juce_ApplicationCommandTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/commands/juce_KeyPressMappingSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/components/juce_CachedComponentImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/components/juce_Component.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/components/juce_Component.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/components/juce_ComponentListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/components/juce_ComponentListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/components/juce_ModalComponentManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/desktop/juce_Desktop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/desktop/juce_Desktop.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/desktop/juce_Displays.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/desktop/juce_Displays.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/drawables/juce_Drawable.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/drawables/juce_Drawable.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableComposite.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawablePath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableShape.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/drawables/juce_DrawableText.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/drawables/juce_SVGParser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_ContentSharer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsDisplayComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_DirectoryContentsList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileBrowserListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileChooserDialogBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FilenameComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FilePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileSearchPathListComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_FileTreeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/filebrowser/juce_ImagePreviewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_CaretComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_KeyboardFocusTraverser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_KeyListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_KeyPress.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_ModifierKeys.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_SystemClipboard.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_TextEditorKeyMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/keyboard/juce_TextInputTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_AnimatedPosition.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_AnimatedPositionBehaviours.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentAnimator.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentBoundsConstrainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentBuilder.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ComponentMovementWatcher.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ConcertinaPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_FlexBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_FlexBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_FlexItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_Grid.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_Grid.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_GridItem.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_GridItem.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_GridUnitTests.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_GroupComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_MultiDocumentPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ResizableBorderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ResizableCornerComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ResizableEdgeComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_ScrollBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_SidePanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_SidePanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutManager.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_StretchableLayoutResizerBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_StretchableObjectResizer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_TabbedButtonBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_TabbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_Viewport.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/layout/juce_Viewport.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V1.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V2.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V3.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/lookandfeel/juce_LookAndFeel_V4.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/menus/juce_BurgerMenuComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/menus/juce_MenuBarComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/menus/juce_MenuBarModel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/menus/juce_PopupMenu.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/misc/juce_BubbleComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/misc/juce_DropShadower.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/misc/juce_DropShadower.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/misc/juce_JUCESplashScreen.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_ComponentDragger.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropContainer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_DragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_FileDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_LassoComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseCursor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseEvent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseInactivityDetector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseInputSource.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_MouseListener.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_SelectedItemSet.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_TextDragAndDropTarget.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/mouse/juce_TooltipClient.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_android_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_android_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_android_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_common_MimeTypes.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_ios_ContentSharer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_ios_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_ios_UIViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_ios_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_linux_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_linux_X11.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_linux_X11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_linux_X11_Clipboard.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_linux_X11_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_mac_FileChooser.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_mac_MainMenu.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_mac_MouseCursor.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_mac_NSViewComponentPeer.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_mac_Windowing.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_MultiTouchMapper.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_win32_DragAndDrop.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_win32_FileChooser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/native/juce_win32_Windowing.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/positioning/juce_MarkerList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinate.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeCoordinatePositioner.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeParallelogram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativePoint.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativePointPath.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/positioning/juce_RelativeRectangle.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_BooleanPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_ButtonPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_ChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_MultiChoicePropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_PropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_PropertyPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_SliderPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/properties/juce_TextPropertyComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ComboBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ImageComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_Label.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_Label.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ProgressBar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_Slider.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_Slider.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TableHeaderComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TableListBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TextEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_Toolbar.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemFactory.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_ToolbarItemPalette.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TreeView.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/widgets/juce_TreeView.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_AlertWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_CallOutBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_ComponentPeer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_DialogWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_DocumentWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_NativeMessageBox.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_ResizableWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_ThreadWithProgressWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_TooltipWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/windows/juce_TopLevelWindow.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/juce_gui_basics.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/juce_gui_basics.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_basics/juce_gui_basics.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CodeDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CodeEditorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_CPlusPlusCodeTokeniserFunctions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_LuaCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/code_editor/juce_XMLCodeTokeniser.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/documents/juce_FileBasedDocument.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/embedding/juce_ActiveXControlComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/embedding/juce_AndroidViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/embedding/juce_NSViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/embedding/juce_ScopedDPIAwarenessDisabler.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/embedding/juce_UIViewComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/embedding/juce_XEmbedComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_AnimatedAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_AppleRemote.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_BubbleMessageComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_ColourSelector.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_KeyMappingEditorComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_LiveConstantEditor.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_PreferencesPanel.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_PushNotifications.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_RecentlyOpenedFilesList.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_SplashScreen.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_SystemTrayIconComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/misc/juce_WebBrowserComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_android_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_android_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_AndroidViewComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_ios_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_ios_UIViewComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_linux_X11_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_linux_X11_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_linux_XEmbedComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_mac_AppleRemote.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_mac_CarbonViewWrapperComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_mac_NSViewComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_mac_PushNotifications.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_mac_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_mac_WebBrowserComponent.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_win32_ActiveXComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_win32_SystemTrayIcon.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/native/juce_win32_WebBrowserComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/juce_gui_extra.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/juce_gui_extra.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_gui_extra/juce_gui_extra.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/geometry/juce_Draggable3DOrientation.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/geometry/juce_Matrix3D.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/geometry/juce_Quaternion.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/geometry/juce_Vector3D.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/native/juce_MissingGLDefinitions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/native/juce_OpenGL_android.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/native/juce_OpenGL_ios.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/native/juce_OpenGL_linux_X11.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/native/juce_OpenGL_osx.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/native/juce_OpenGL_win32.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/native/juce_OpenGLExtensions.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLFrameBuffer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLGraphicsContext.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLHelpers.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLImage.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLPixelFormat.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLRenderer.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLShaderProgram.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/opengl/juce_OpenGLTexture.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/utils/juce_OpenGLAppComponent.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/juce_opengl.cpp" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/juce_opengl.mm" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../../../JUCE/modules/juce_opengl/juce_opengl.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../JuceLibraryCode/AppConfig.h" PROPERTIES HEADER_FILE_ONLY TRUE)
set_source_files_properties("../../../JuceLibraryCode/JuceHeader.h" PROPERTIES HEADER_FILE_ONLY TRUE)

find_library(log "log")
find_library(android "android")
find_library(glesv2 "GLESv2")
find_library(egl "EGL")

target_link_libraries( ${BINARY_NAME}

    ${log}
    ${android}
    ${glesv2}
    ${egl}
    "cpufeatures"
)
