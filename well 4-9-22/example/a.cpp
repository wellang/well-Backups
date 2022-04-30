#include <wellang/well.hpp>
void 
while_func() {
//func:while_func() {

	stack program(4);

	int i = 0;

while(i != 5) {

	program.push(34);
	program.push(35);
	program.plus();
	program.dump();

	i++;

}

}

int main() {
//func:main() {

	while_func();

}
