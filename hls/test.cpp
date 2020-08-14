#include "top.h"
int main(int argc, char const *argv[])
{
	stream<ap_axis > inputStream1;
	for (unsigned int i = 0; i < 8; i++) {
		ap_axis temp;
		temp.data =i;
		cout << "inputStream1[" << i << "]: " << hex << temp.data << dec << endl;
		inputStream1.write(temp);
	}
	stream<ap_axis > inputStream2;
	for (unsigned int i = 0; i < 8; i++) {
		ap_axis temp;
		temp.data =i;
		cout << "inputStream2[" << i << "]: " << hex << temp.data << dec << endl;
		inputStream2.write(temp);
	}
	stream<ap_axis > outputStream;
	top_function(inputStream1,inputStream2,outputStream,1);
	for (unsigned int i = 0; i < 8; i++) {
		ap_axis temp;
		temp=outputStream.read();
		cout << "outputStream[" << i << "]: " << hex << temp.data << dec << endl;
	}
	return 0;
}
