### Build guide:

Run the following command:

```
docker build . -t bin-random
```
This command will build the docker container and name it bin-random


```
docker run -d -p2224:2224 --name random bin-random
```
This command will run the docker contianer in detach mode, it will expose port 2224 and name the container random

The shell is available at
```console
ssh ctf@localhost -p 2224
```