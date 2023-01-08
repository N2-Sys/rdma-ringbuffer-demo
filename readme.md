# RDMA ringbuffer demo
A implementation of the ringbuffer part of [FaRM](https://www.usenix.org/conference/nsdi14/technical-sessions/dragojevi%C4%87).

A benchmark is used to test throughput performance under different message size. 
The benchmark program contains a producer and a consumer.
- producer produces message in a fixed size.
- and consumer consumes it.

How to use the benchmark:
1. Modify `include/demo.h`:
   - `producer_name` and `consumer_name`
      These two value will be used to reach the other side. 
      It can be the same if you want to run the benchmark locally.
   - `device_name`
      run command `ibv_devinfo` and fill it with the `hca_id` you want to use. 


2. Run `mkdir build && cd build` and `cmake ..` and `make` (or `make -j` if you want to speed it up)
3. Copy the whole working directory to the producer side and consumer side.
4. Run `./producer` and `./consumer` in the corresponding server. 
5. Wait for the test result. The whole process typically takes about 20~40 minutes for 100GB testing. The result will be printed to the terminal, and you can also get it from `build/prod.csv` in the procuder side.

There are some other adjustable configurations, see `demo.h`.

p.s.: Sorry for the inconvenience out of the poor organization of the project and the old-fashioned code.