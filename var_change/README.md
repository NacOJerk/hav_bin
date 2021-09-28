### Build guide:

Run the following command:

```
docker build . -t bin-var-change
```
This command will build the docker container and name it bin-var-change


```
docker run -d -p2222:2222 --name var-change bin-var-change
```
This command will run the docker contianer in detach mode, it will expose port 2222 and name the container var-change

The shell is available at
```console
ssh ctf@localhost -p 2222
```