# infraestrutura-de-ti-t1
Trabalho 1 da cadeira de Infraestrutura de Tecnologia de Informação - 2021/2.

## Aplicação empacotada

É uma simples aplicação web, com linguagem Java e framework Spring. Nela, há um endpoint `GET /hello-world` que retornará uma mensagem "Hello, world".

## Dockerfile

```dockerfile
FROM openjdk:11.0.1-jre-slim-stretch // utilizando uma imagem reduzida para executar a aplicação java
EXPOSE 56060 // expondo a aplicação na porta 56060, configurada no arquivo application.properties.
COPY build/libs/hello-world.jar /hello-world.jar // copiando o conteúdo do jar gerado para a raíz
ENTRYPOINT ["java", "-jar", "/hello-world.jar"] // executando a aplicação java
```
