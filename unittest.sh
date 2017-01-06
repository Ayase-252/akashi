cmake .
make DESTDIR=. install

cd test-bin && run-parts .
cd ~/projects/process-communicator
