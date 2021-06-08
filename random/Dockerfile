FROM ubuntu:latest

RUN apt update && apt install -y openssh-server sudo gcc gdb
RUN apt install -y g++-multilib
RUN useradd -rm -d /home/ubuntu -s /bin/bash -g root -G sudo -u  1001 ctf_flag
RUN useradd -rm -d /home/ubuntu -s /bin/bash -u 1000 ctf

RUN  echo 'ctf:ctf' | chpasswd


WORKDIR /home/ubuntu


USER ctf_flag
COPY . .
RUN rm Dockerfile
RUN gcc -m32 random.c -o random -no-pie -fno-stack-protector

USER root
RUN chown ctf_flag: flag random.c random
RUN chmod oug-rwx flag random.c
RUN chmod ouo+r random.c
RUN chmod ug+r flag

USER ctf_flag
RUN chmod u+s random
USER root

RUN service ssh start

EXPOSE 2224

CMD ["/usr/sbin/sshd","-D", "-p", "2224"]