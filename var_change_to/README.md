### Build guide:

Run the following command:

```
docker build . -t bin-var-change-to
```
This command will build the docker container and name it bin-var-change-to


```
docker run -d -p2225:2225 --name var-change-to bin-var-change-to
```
This command will run the docker contianer in detach mode, it will expose port 2225 and name the container var-change-to

The shell is available at
```console
ssh ctf@localhost -p 2225
```