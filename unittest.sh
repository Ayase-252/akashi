cmake .
make DESTDIR=. install

cd test-bin && run-parts .
cd .. && rm -rf test-bin
cd ~/projects/process-communicator
