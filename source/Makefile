CXX=clang++
CXXFLAGS=-MMD -MP -std=c++11 -g -Wall -Wextra -pedantic -Werror -Ofast 
CL=cl
CLFLAGS=/wd4514 /wd4710 /wd4571 /wd4774 /wd4365 /wd4625 /wd4711 /wd4820 /wd4626 /wd5026 /wd5027 /wd4265 /wd4623 /Wall /EHs /O2 /Ot /favor:INTEL64 /Qspectre /analyze /GA /GL /cgthreads8 /MP /Gs 
OUTPUT=graph

linux:
	$(CXX) $(CXXFLAGS) -o $(OUTPUT) *.cpp

windows: 
	$(CL) *.cpp $(CLFLAGS) /Fe$(OUTPUT).exe