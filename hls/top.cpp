#include <stdint.h>
#include "top.h"

void top_function(stream<ap_axis >& in,stream<ap_axis >& in2, stream<ap_axis >& out, const unsigned int control)
{
#pragma HLS INTERFACE axis register both port=out
#pragma HLS INTERFACE axis register both port=in
#pragma HLS INTERFACE axis register both port=in2
#pragma HLS INTERFACE s_axilite port=control bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control
	if(control==1)
	{
		ap_uint<32> line_buffer[8];
		ap_uint<32> line_buffer1[8];
		ap_uint<32> line_buffer2[8];
		for (unsigned i=0;i<8;i++)
		{
			line_buffer1[i]=in.read().data;
			line_buffer2[i]=in2.read().data;
		}
		unroll1:for (unsigned i=0;i<8;i++)
		{
			line_buffer[i]=line_buffer1[i]+line_buffer2[i];
		}
		ap_axis temp;
		temp.keep=0xf;
		for (unsigned i = 0; i < 8-1; i++) {
				temp.data = line_buffer[i];
				temp.last = 0;
				out.write(temp);
		}

		temp.data = line_buffer[7];
		temp.last = 1;
		out.write(temp);
	}
	if(control==2)
	{

			ap_uint<32> line_buffer[8];
			ap_uint<32> line_buffer1[8];
			ap_uint<32> line_buffer2[8];
			for (unsigned i=0;i<8;i++)
			{
				line_buffer1[i]=in.read().data;
				line_buffer2[i]=in2.read().data;
			}
			pipeline1:for (unsigned i=0;i<8;i++)
			{
				line_buffer[i]=line_buffer1[i]+line_buffer2[i];
			}
			ap_axis temp;
			temp.keep=0xf;
			for (unsigned i = 0; i < 8-1; i++) {
					temp.data = line_buffer[i];
					temp.last = 0;
					out.write(temp);
			}

			temp.data = line_buffer[7];
			temp.last = 1;
			out.write(temp);
		}
	if(control==3)
		{

				ap_uint<32> line_buffer[8];
				ap_uint<32> line_buffer1[8];
				ap_uint<32> line_buffer2[8];
				for (unsigned i=0;i<8;i++)
				{
					line_buffer1[i]=in.read().data;
					line_buffer2[i]=in2.read().data;
				}
				for (unsigned i=0;i<8;i++)
				{
					line_buffer[i]=line_buffer1[i]+line_buffer2[i];
				}
				ap_axis temp;
				temp.keep=0xf;
				for (unsigned i = 0; i < 8-1; i++) {
						temp.data = line_buffer[i];
						temp.last = 0;
						out.write(temp);
				}

				temp.data = line_buffer[7];
				temp.last = 1;
				out.write(temp);
			}
}
