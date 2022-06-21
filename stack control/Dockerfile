FROM ubuntu:latest

RUN apt update && apt install -y openssh-server sudo gcc gdb
RUN apt install -y g++-multilib
RUN apt install -y nano
RUN useradd -rm -d /home/ubuntu -s /bin/bash -g root -G sudo -u  1001 ctf_flag
RUN useradd -rm -d /home/ubuntu -s /bin/bash -u 1000 ctf

RUN  echo 'ctf:ctf' | chpasswd


WORKDIR /home/ubuntu


USER ctf_flag
COPY flag stackcontrol.c ./
RUN gcc -m32 stackcontrol.c -o stackcontrol -no-pie -fno-stack-protector

USER root
RUN chown ctf_flag: flag stackcontrol.c stackcontrol
RUN chmod oug-rwx flag stackcontrol.c
RUN chmod ouo+r stackcontrol.c
RUN chmod ug+r flag

USER ctf_flag
RUN chmod u+s stackcontrol
USER root
RUN chown ctf: /home/ubuntu

RUN service ssh start

EXPOSE 2223

CMD ["/usr/sbin/sshd","-D", "-p", "2223"]