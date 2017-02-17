// All systemc modules should include systemc.h header file
#include "systemc.h"

SC_MODULE (count_compare) {
  sc_in_clk     clock;
  sc_in<bool>   load1;
  sc_in<bool>   dec1;
  sc_in<bool>   load2;
  sc_in<bool>   dec2;
  sc_in<sc_uint<8> > in1;
  sc_in<sc_uint<8> > in2;
  sc_in<sc_uint<8> > in3;

  sc_out<bool> ended;
  sc_out<sc_uint<8> > count1;
  sc_out<sc_uint<8> > count2;

  //------------Local Variables Here---------------------
  sc_uint<8> var_count1;
  sc_uint<8> var_count2;
  sc_uint<8> var_in3;
  bool var_ended;

  //------------Code Starts Here-------------------------

  void assignment() {
    cout << "@" << sc_time_stamp() << "Executing......"<<endl;

    //********* counter 1 *********//
    if (load1.read() == 1)
    {
      var_count1 = in1.read();
      var_ended = false;
      // ended.write(0);
    }
    if (!var_ended && dec1.read() == 1)
    {
      if (var_count1 > 0)
      {
        var_count1 --;
      }
      else
      {
        var_ended = true;
        // ended.write(1);
      }
    }

    //********* counter 2 *********//
    if (load2.read() == 1)
    {
      var_count2 = in2.read();
      var_ended = false;
      // ended.write(0);
    }
    if (!var_ended && dec2.read() == 1)
    {
      if (var_count2 >= in3)
      {
        var_in3 = in3;
        var_count2 = var_count2 - var_in3;
      }
      else
      {
        var_ended = true;
        // ended.write(1);
      }
    }

    // equality check
    if (var_count1 == var_count2)
    {
      var_ended = true;
      // ended.write(1);
    }
    count1.write(var_count1);
    count2.write(var_count2);
    ended.write(var_ended);
  }

  SC_CTOR(count_compare) {
    var_count1 = 0;
    var_count2 = 0;
    var_ended = false;
    SC_METHOD(assignment);
    sensitive << clock.pos();
  } 

}; // End of Module

// sc_main in top level function like in C++ main
int sc_main(int argc, char* argv[]) {
  sc_signal<bool> clock;
  sc_signal<bool> load1;
  sc_signal<bool> load2;
  sc_signal<bool> dec1;
  sc_signal<bool> dec2;
  sc_signal<sc_uint<8> > in1;
  sc_signal<sc_uint<8> > in2;
  sc_signal<sc_uint<8> > in3;

  sc_signal<sc_uint<8> > count1;
  sc_signal<sc_uint<8> > count2;
  sc_signal<bool > ended;

  count_compare modules1("modules1");
  modules1.clock(clock);
  modules1.load1(load1);
  modules1.load2(load2);
  modules1.dec1(dec1);
  modules1.dec2(dec2);
  modules1.in1(in1);
  modules1.in2(in2);
  modules1.in3(in3);

  modules1.count1(count1);
  modules1.count2(count2);
  modules1.ended(ended);

  sc_trace_file *wf = sc_create_vcd_trace_file("countcompare");
  sc_trace(wf, clock, "clock");
  sc_trace(wf, load1, "load1");
  sc_trace(wf, load2, "load2");
  sc_trace(wf, dec1, "dec1");
  sc_trace(wf, dec2, "dec2");
  sc_trace(wf, in1, "in1");
  sc_trace(wf, in2, "in2");
  sc_trace(wf, in3, "in3");
  sc_trace(wf, count1, "count1");
  sc_trace(wf, count2, "count2");
  sc_trace(wf, ended, "ended");

  in1 = 55;
  in2 = 74;
  in3 = 20;
  load1 = true;
  dec1 = false;
  load2 = true;
  dec2 = false;
  clock = 1;
  sc_start(10, SC_NS);
  clock = 0;
  sc_start(10, SC_NS);
  cout <<"count1:"<<count1<<" count2:"<<count2<<" ended:"<<ended<<endl;

  load1 = false;
  dec1 = true;
  load2 = false;
  dec2 = false;
  clock = 1;
  sc_start(10, SC_NS);
  clock = 0;
  sc_start(10, SC_NS);
  cout <<"count1:"<<count1<<" count2:"<<count2<<" ended:"<<ended<<endl;

  load1 = false;
  dec1 = false;
  load2 = false;
  dec2 = true;
  clock = 1;
  sc_start(10, SC_NS);
  clock = 0;
  sc_start(10, SC_NS);
  cout <<"count1:"<<count1<<" count2:"<<count2<<" ended:"<<ended<<endl;

  load1 = false;
  dec1 = true;
  load2 = false;
  dec2 = false;
  clock = 1;
  sc_start(10, SC_NS);
  clock = 0;
  sc_start(10, SC_NS);
  cout <<"count1:"<<count1<<" count2:"<<count2<<" ended:"<<ended<<endl;

  load1 = true;
  dec1 = false;
  load2 = false;
  dec2 = false;
  clock = 1;
  sc_start(10, SC_NS);
  clock = 0;
  sc_start(10, SC_NS);
  cout <<"count1:"<<count1<<" count2:"<<count2<<" ended:"<<ended<<endl;

  load1 = false;
  dec1 = false;
  load2 = false;
  dec2 = true;
  clock = 1;
  sc_start(10, SC_NS);
  clock = 0;
  sc_start(10, SC_NS);
  cout <<"count1:"<<count1<<" count2:"<<count2<<" ended:"<<ended<<endl;

  load1 = false;
  dec1 = false;
  load2 = false;
  dec2 = true;
  clock = 1;
  sc_start(10, SC_NS);
  clock = 0;
  sc_start(10, SC_NS);
  cout <<"count1:"<<count1<<" count2:"<<count2<<" ended:"<<ended<<endl;

  load1 = false;
  dec1 = true;
  load2 = false;
  dec2 = true;
  clock = 1;
  sc_start(10, SC_NS);
  clock = 0;
  sc_start(10, SC_NS);
  cout <<"count1:"<<count1<<" count2:"<<count2<<" ended:"<<ended<<endl;

  load1 = false;
  dec1 = true;
  load2 = false;
  dec2 = false;
  clock = 1;
  sc_start(10, SC_NS);
  clock = 0;
  sc_start(10, SC_NS);
  cout <<"count1:"<<count1<<" count2:"<<count2<<" ended:"<<ended<<endl;

  sc_close_vcd_trace_file(wf);
  return(0);
}

