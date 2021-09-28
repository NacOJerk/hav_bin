### Build guide:

Run the following command:

```
docker build . -t bin-stack-control
```
This command will build the docker container and name it bin-stack-control


```
docker run -d -p2223:2223 --name stack-control bin-stack-control
```
This command will run the docker contianer in detach mode, it will expose port 2223 and name the container stack-control

The shell is available at
```console
ssh ctf@localhost -p 2223
```