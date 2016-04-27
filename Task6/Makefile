ArrayViewer.out: ArrayViewer.cpp ArrayOperations.h ArrayOperations.cpp
	g++ ArrayViewer.cpp ArrayOperations.h ArrayOperations.cpp -o ArrayViewer.out
ArrayOperationsTester.out: ArrayOperationsTester.cpp ArrayOperations.h ArrayOperations.cpp
	g++ ArrayOperationsTester.cpp ArrayOperations.h ArrayOperations.cpp -o ArrayOperationsTester.out

test: ArrayOperationsTester.out
	./ArrayOperationsTester.out

run: ArrayViewer.out
	./ArrayViewer.out
