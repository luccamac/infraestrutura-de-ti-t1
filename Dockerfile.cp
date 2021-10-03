FROM openjdk:11.0.4-jre-slim-stretch
EXPOSE 56060
COPY build/libs/hello-world.jar /hello-world.jar
ENTRYPOINT ["java","-jar", "/hello-world.jar"]
