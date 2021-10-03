FROM openjdk:11.0.1-jre-slim-stretch
EXPOSE 56060
COPY build/libs/hello-world.jar /app.jar
ENTRYPOINT ["java","-jar", "/app.jar"]