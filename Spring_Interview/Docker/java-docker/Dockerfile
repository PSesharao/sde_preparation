FROM openjdk:8

LABEL authors="SESH"

WORKDIR /usr/src/myapp

#To copy the files of the src to the WORKDIR
COPY ./src .

RUN javac Test.java

CMD [ "java" , "Test"]
