set (SRCS 
	main.cpp 
	MainWindow.cpp
	PlayerSheet.cpp)

set (HEADERS MainWindow.h
	PlayerSheet.h)

set (UI 
	Mainwindow.ui)

qt_add_executable(AkropolisSheet
    ${UI} 
    ${SRCS} 
    ${HEADERS}
)

target_link_libraries(AkropolisSheet PRIVATE Qt6::Widgets)

set_target_properties(AkropolisSheet PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)