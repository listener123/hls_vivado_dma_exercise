#include <hls_stream.h>
#include <ap_int.h>
using namespace hls;
using namespace std;
// axi data
struct ap_axis{
	ap_uint<32> data;
	ap_uint<1> last;
	ap_uint<64> keep;
};
void top_function(stream<ap_axis >& in,stream<ap_axis >& in2, stream<ap_axis >& out, const unsigned int control);
