/**
 * @page install mtoc++ installation instructions
 *
 * Make sure you have the latest version of mtoc++, see @ref download. Next step after installation is @ref tools
 *
 * @section inst_req Software requirements and recommendations
 * The following programs need to be available on your machine in order to use mtoc++:
 * - \c doxygen (>=1.7.3): mtoc++ is a filter for doxygen. If not yet available, get it at http://www.doxygen.org
 * - \c m4: A macro processor http://www.gnu.org/s/m4/ (For Windows we included a m4 executable in the download!)
 *
 * The following programs will highly improve your documentation creation experience if available:
 * - \c dot: A Graphviz tool that allows doxygen to create nice graphics for inheritance trees and collaboration diagrams.
 * - \c latex: Required to use LaTeX processing capabilities of doxygen (e.g. http://www.latex-project.org/ftp.html).
 *  mtoc++ comes with some markups for better latex inclusion into the text flow.
 *  Also, easy inclusion of external latex sources and styles is included in mtoc++'s tools.
 * - \c ghostscript: If using formulas with doxygen and you are not using pdflatex or are on a windows machine, this
 *  is a prerequisite (see http://www.stack.nl/~dimitri/doxygen/install.html#install_bin_windows)
 *
 * If you want to build mtoc++ from source, you will also need:
 * - Ragel: A finite-state machine compiler. Get at http://www.complang.org/ragel
 * - CMake: Cross-platform make. Get at http://www.cmake.org
 * - dirent.h (We included a Visual Studio API implementation by Tony Ronkko for Windows)
 *
 * @section inst_binaries Using precompiled binaries
 * @subsection inst_binaries_win Windows users
 *
 * If you are a windows user you can directly download the binaries at @ref download.
 * Note that you might need to install the Microsoft Visual C++ 2010 redistributables first,
 * which can be found <a href="http://www.microsoft.com/download/en/confirmation.aspx?id=8328" target="_blank">here</a>.
 * Then simply place the binaries in a folder of your choice and add them to the PATH environment variable.
 *
 * @note Doxygen and mtoc++ expect certain programs to be available via the PATH environment variable, e.g. \c latex.exe or \c gswin32c.exe
 * must be present in order for doxygen to work. Make sure that you have all requirements available. You can check/change your Windows
 * PATH environment variable via the sequence
 * @code Computer \ Properties \ Advanced system settings \ Environment Variables \ Edit Path @endcode
 * If you intend to use the MatlabDocMaker, you can also copy the binaries into the "documentation configuration files" folder
 * for your/each project, this path will be added to PATH by MatLab locally.
 *
 * We are trying to always compile current Windows binaries for \c mtocpp and \c mtocpp_post and include them for direct download.
 *
 * @subsection inst_binaries_unix Unix binaries
 * For unix users we recommend to compile the sources following @ref inst_comp.
 * However, we also plan to provide some precompiled linux binaries/packages soon.
 *
 * If you find a matching choice you can use it and all you have to do is to ensure that the binaries can be found on the environment PATH.
 *
 * @section inst_comp Compiling mtoc++ from source
 * Please check the @ref inst_req when you intend to build mtoc++ yourself.
 *
 * mtoc++ is built using the cmake (cross-platform make) tool. This tool is available for both unix and Windows,
 * however, we only tested compiling our sources on linux and MS Visual Studio 2010.
 *
 * @subsection inst_comp_win Windows platforms
 * For Windows compilation, you need a Windows C++ compiler (e.g. MinGW or Visual Studio). Then running
 * the CMake GUI allows you to choose a compiler, specify any CMake configuration settings and create the
 * makefiles/Visual Studio projects needed for compilation.
 *
 * Furthermore, we're using the \c dirent.h library for file access. As this is a linux library we've included a file
 * \c dirent_msvc.h in our source, which implements the dirent api for Microsoft Visual Studio and was written by Tony Ronkko.
 * More information and downloads can be found at http://www.softagalleria.net/dirent.php.
 *
 * @note On Windows, you can build both 32bit and 64bit versions. If you build with Visual Studio, in recent CMake versions you need to specify the target architecture
 * already when choosing the generator ("Visual Studio 10 / Visual Studio 10 Win64"). This sets up the VS2010 project with the correct platforms.
 * In general, you can of course also use 64bit binaries from ragel and doxygen, but this is not required for successful 64bit-compilation of mtoc++ .
 *
 * @subsection inst_comp_unix Unix platforms
 *
 * The following procedure is an example of how to compile mtoc++ on a linux machine:
 * @code tar -xcvf mtocpp.tar.gz
 * cd mtocpp
 *
 * # Create build folder (optional, but more clean)
 * mkdir build
 * cd build
 *
 * # Run cmake
 * cmake ..
 * make install
 * @endcode
 *
 * @attention Please be aware that, depending on your installation location, you might need different access/write permissions.
 * For most cases, a @code sudo make install@endcode will do the job if the above snippet fails.
 *
 * @subsection inst_cust CMake options: Installation folders and customization
 *
 * @note These options are explained for the linux case, for windows the CMake GUI allows to set the relevant options.
 *
 * The default value for the install prefix is \c /usr/local, so the mtocpp binaries \c mtocpp and \c mtocpp_post go to \c /usr/local/bin
 * and the documentation is created inside \c /usr/local/share/doc/mtocpp.
 *
 * If you want the "make install" command to copy the binaries and documentation to different locations, you can choose them by setting the following variables:
 * - CMAKE_INSTALL_PREFIX: Set this to whatever location you want mtoc++ to be installed. Note that the binaries are effectively copied into "CMAKE_INSTALL_PREFIX/bin" in order to comply with linux standards.
 * - CUSTOM_DOC_DIR: This value is "CMAKE_INSTALL_PREFIX/share/doc/mtocpp" per default.
 *
 * So typing
 * @code cmake -DCMAKE_INSTALL_PREFIX="/my/root/dir" -DCUSTOM_DOC_DIR="/my/docs" @endcode
 * will copy the binaries to \c /my/root/dir/bin and the documentation to \c /my/docs.
 *
 * If you left the \c CUSTOM_DOC_DIR flag empty the documentation would have gone to \c /my/root/dir/share/doc/mtocpp
 *
 * @section inst_test Testing
 * mtoc++ comes with some unit tests to check for e.g. successful compilation.
 * Run the tests by typing
 * @code make test @endcode
 * in the same folder where you called \c cmake.
 *
 * On Windows, dedendent on your compiler, you will either have makefiles for the test cases or a separate Visual Studio project to run the tests.
 *
 * Have fun!
 *
 * @page troubleshooting Troubleshooting
 * @short Some hopefully useful hints when things dont go as they should!
 *
 * @section sec_ts Troubleshooting mtoc++
 * @subsection ssec_doxyknowledge KNOWLEDGE OF DOXYGEN IS ESSENTIAL!
 *
 * mtoc++ is designed as a filter for MatLab m-files, so that they can be processed by doxygen as if they were C source files.
 * Everything else regarding tags, conventions and possible formatting of display is completely defined by Doxygen.
 * So, unless explicitly explained as "feature" of mtoc++ here, one should look into Doxygen's <a href="http://www.stack.nl/~dimitri/doxygen/manual.html" target="_blank">documentation pages</a>
 * first before complaining about some stuff that mtoc++ surprisingly cannot do.
 *
 * So, if you want to connect mtoc++ to your MatLab project without using the MatlabDocMaker, you need to understand some of the principals on how doxygen and mtoc++ work together.
 * In this context, the file @code Doxyfile.m4 @endcode included in the tools folder is essential to connect mtoc++ successfully to Doxygen.
 * Everything related to mtoc++ has been put to the very bottom of the file:
 * @code
 * EXTENSION_MAPPING = .m=C++
 * INPUT             = _SourceDir_ _ConfDir_
 * FILE_PATTERNS     = *.m
 * FILTER_PATTERNS   = *.m="_ConfDir_`'_FileSep_`'_MTOCFILTER_"
 * @endcode
 * Here, the underscored values will get replaced by the MatlabDocMaker in order to insert the correct values.
 * Essentially:
 * - \c EXTENSION_MAPPING tells doxygen to regard \c .m-Files as if they were \c C++ files, style-wise.
 * - \c INPUT tells doxygen where to look for files.
 * - \c FILE_PATTERNS lets doxygen also look for \c .m-Files.
 * - \c FILTER_PATTERNS is the most important line of the configuration. Here, you need to define scripts that should be called by doxygen before certain files are processed.
 * The MatlabDocMaker automatically generates and inserts a correct script there in order to "inject" mtoc++ into doxygen for every file read by doxygen.
 * If you dont use the tool, you will need to define your own filter script that passes the argument to mtoc++, using a possible configuration file.
 *
 * @subsection ssec_debug Debugging mtoc++
 * For hard cases like segfaults there is also hope!
 *
 * You can build your mtoc++ binaries with the \c Debug build type (starting in the source folder):
 * @code
 * mkdir build
 * cd build
 * cmake -DCMAKE_BUILD_TYPE=Debug ..
 * make
 * @endcode
 * Then, send the compiled binaries along with the used source code to us and we will try to figure out what the heck is wrong with it!
 *
 */
