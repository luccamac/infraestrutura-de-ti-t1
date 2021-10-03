# Trabalho 1 - Infraestrutura de TI - Docker
Trabalho 1 da cadeira de Infraestrutura de Tecnologia de Informação - 2021/2.

## Aplicação
É uma simples aplicação web, com linguagem Java e framework Spring. Nela, há um endpoint `GET /hello-world` que retornará uma mensagem "Hello, world".


## Dockerfile
```dockerfile
FROM openjdk:11-jre-slim-stretch // utilizando uma imagem reduzida do openjdk do java, a fim de poupar recursos desnecessários
EXPOSE 56060 // expondo a aplicação na porta 56060, configurada no arquivo application.properties
COPY build/libs/hello-world.jar /hello-world.jar // copiando o conteúdo do jar gerado para a raíz
ENTRYPOINT ["java", "-jar", "/hello-world.jar"] // executando a aplicação java
```

## Geração da Imagem
Tendo o projeto no servidor, foi rodado o comando `docker build` para a geração da imagem.

```
ubuntu@ip-172-31-17-113:~/infraestrutura-de-ti-t1$ docker build -f ./Dockerfile.cp -t luccamac/hello-world-java-spring .
Sending build context to Docker daemon  33.53MB
Step 1/4 : FROM openjdk:11-jre-slim-stretch
11-jre-slim-stretch: Pulling from library/openjdk
743f2d6c1f65: Pull complete
5c14188d0980: Pull complete
84a54a21b0f2: Pull complete
d9d1bc98b287: Pull complete
c99e982badff: Pull complete
50c6b4dfde57: Pull complete
Digest: sha256:49b7efb61374586c9c007adc306dcaf248ba4250286a9a40d7f0b9a546f0bb25
Status: Downloaded newer image for openjdk:11-jre-slim-stretch
 ---> a71b975306d9
Step 2/4 : EXPOSE 56060
 ---> Running in ce36d043da31
Removing intermediate container ce36d043da31
 ---> a6937ce9a178
Step 3/4 : COPY build/libs/hello-world.jar /hello-world.jar
 ---> 294ae2d61e7c
Step 4/4 : ENTRYPOINT ["java","-jar", "/hello-world.jar"]
 ---> Running in 44c4edd50397
Removing intermediate container 44c4edd50397
 ---> 4379c517d8cb
Successfully built 4379c517d8cb
Successfully tagged luccamac/hello-world-java-spring:latest
```

Após isso, rodou-se a imagem e um `docker ps` para validar se o container estava em execução.

```
ubuntu@ip-172-31-17-113:~/infraestrutura-de-ti-t1$ docker run -d --name hello-world-java -p 56060:56060 luccamac/hello-world-java-spring
9ac63ed77eae60bc0198bbaabdada61634519bfa67e8e6057a7ce2fc9d815729

ubuntu@ip-172-31-17-113:~/infraestrutura-de-ti-t1$ docker ps
CONTAINER ID   IMAGE                              COMMAND                  CREATED         STATUS         PORTS                                           NAMES
9ac63ed77eae   luccamac/hello-world-java-spring   "java -jar /hello-wo…"   6 seconds ago   Up 5 seconds   0.0.0.0:56060->56060/tcp, :::56060->56060/tcp   hello-world-java
```

Logo, pode-se executar um comando cURL para verificar se a requisição estava sendo processada.

```
ubuntu@ip-172-31-17-113:~/infraestrutura-de-ti-t1$ curl http://localhost:56060/hello-world
Hello, world!
```
