FROM gcc:latest

WORKDIR /home/styx/tester

COPY . ./

RUN adduser app
RUN touch hello_world
RUN chmod 777 hello_world

USER app

RUN gcc test.c -o hello_world

CMD [ "./hello_world", "alligator" ]
