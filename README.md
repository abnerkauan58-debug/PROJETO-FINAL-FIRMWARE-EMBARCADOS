# PROJETO-FINAL-FIRMWARE-EMBARCADOS
Documentação completa de um sistema embarcado para monitoramento e controle de uma estufa, utilizando a Franzininho WiFi LAB01.
# 🌱 Sistema de Monitoramento e Controle de Estufa com ESP32

## 📌 Descrição

Este projeto consiste no desenvolvimento de um sistema embarcado utilizando o ESP32 para monitoramento e controle de uma estufa. O sistema realiza a leitura de temperatura, umidade e luminosidade, exibindo os dados em um display OLED e permitindo interação com o usuário através de um menu.

Além disso, os dados coletados podem ser armazenados na memória interna do ESP32 e posteriormente acessados via comunicação serial.

---

## ⚙️ Funcionalidades

* 📡 Monitoramento em tempo real:

  * Temperatura e umidade (DHT11)
  * Luminosidade (LDR)

* 📺 Interface com usuário:

  * Exibição dos dados no display OLED (I2C)
  * Menu interativo para ajuste do setpoint

* 🎛️ Controle:

  * Ajuste do setpoint de temperatura
  * Ativação/desativação manual do sistema

* 💾 Armazenamento:

  * Registro de dados em arquivo (`log.txt`) utilizando SPIFFS ou LittleFS
  * Leitura dos dados via terminal serial

---

## 🧰 Hardware Utilizado

* FRANZININHO WIFI LAB 
* Sensor DHT11
* LDR (com divisor de tensão)
* Display OLED (SSD1306 - I2C)
* Botões (para navegação no menu)
( TODOS RECURSOS SÃO INTEGRADOS DA PLACA)
---

## 🏗️ Estrutura do Projeto

```bash
main/
    main.c

components/
    dht/
    ldr/
    oled/
    menu/
    control/
    storage/
```

---

## 🚀 Como Compilar e Executar

### 🔧 Pré-requisitos

* ESP-IDF instalado e configurado
* Python configurado
* Drivers USB do ESP32

---

### ▶️ Passos

1. Clone o repositório:

```bash
git clone https://github.com/seu-usuario/seu-repositorio.git
cd seu-repositorio
```

2. Configure o projeto:

```bash
idf.py menuconfig
```

👉 Aqui você pode configurar:

* pinos dos sensores
* parâmetros padrão
* sistema de arquivos

---

3. Compile o projeto:

```bash
idf.py build
```

---

4. Grave no ESP32:

```bash
idf.py flash monitor
```

---

## 🖥️ Uso do Sistema

* O display OLED mostra:

  * Temperatura
  * Umidade
  * Luminosidade

* O menu permite:

  * Ajustar o setpoint de temperatura
  * Ativar/desativar o sistema
  * Habilitar/desabilitar o log de dados

---

## 📡 Comandos via Serial

Para acessar os dados armazenados:

```bash
readlog
```

👉 O sistema irá imprimir no terminal o conteúdo do arquivo `log.txt`.

---

## 💾 Armazenamento de Dados

Os dados são armazenados no sistema de arquivos (SPIFFS ou LittleFS) no arquivo:

```bash
/spiffs/log.txt
```


## 🧠 Conceitos Aplicados

* Comunicação I2C (OLED)
* Leitura ADC (LDR)
* Comunicação digital (DHT11)
* Sistema de arquivos embarcado (SPIFFS / LittleFS)
* FreeRTOS (tarefas e delays)
* Modularização com componentes (ESP-IDF)
* Controle baseado em setpoint


## ⚙️ Possíveis Melhorias

* Implementação de controle PID (Kp, Ki, Kd)
* Interface web via Wi-Fi
* Comunicação via ESP-NOW
* Armazenamento em cartão SD
* Gráficos em tempo real


## 📷 Diagrama do Sistema

Adicione aqui o diagrama de blocos do hardware:


        +-------------+
        | FRANZININHO |
        +------+------+
               |
   --------------------------
   |           |           |
 DHT11       LDR        OLED
(temp/umid)  (ADC)      (I2C)
```



