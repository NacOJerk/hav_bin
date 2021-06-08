FROM ubuntu:latest

RUN apt update && apt install -y openssh-server sudo gcc gdb
RUN apt install -y g++-multilib
RUN apt install -y nano
RUN useradd -rm -d /home/ubuntu -s /bin/bash -g root -G sudo -u  1001 ctf_flag
RUN useradd -rm -d /home/ubuntu -s /bin/bash -u 1000 ctf

RUN  echo 'ctf:ctf' | chpasswd


WORKDIR /home/ubuntu


USER ctf_flag
COPY . .
RUN rm Dockerfile
RUN gcc -m32 changeto.c -o changeto -no-pie -fno-stack-protector

USER root
RUN chown ctf_flag: flag changeto.c changeto
RUN chmod oug-rwx flag changeto.c
RUN chmod ouo+r changeto.c
RUN chmod ug+r flag

USER ctf_flag
RUN chmod u+s changeto
USER root

RUN service ssh start

EXPOSE 2225

CMD ["/usr/sbin/sshd","-D", "-p", "2225"]