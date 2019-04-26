Agente zabbix de monitoramento no arduino
=========

**Gravação do código no arduino**


**1.** Instalar IDE do arduino (https://www.arduino.cc/en/Main/Software)


**2.** Baixe e coloce na pasta 'libraries' do arduino as seguintes bibliotecas

```
DallasTemperature:  https://github.com/milesburton/Arduino-Temperature-Control-Library

EmonLib:  https://github.com/openenergymonitor/EmonLib

LM35: https://github.com/ggzucco/LM35

OneWire:  https://github.com/PaulStoffregen/OneWire
```

**3.** Abrir IDE arduino


**4.** Modificar código precedido por '// User changeable parameters' de acordo com a necessidade

```
nofSensors:  Modificar valor para o número de sensores de corrente que serão conectados, com número máximo de 13 sensores

gateway:  Modificar valores pelo gateway que deseja que o arduino utilize na rede

subnet:  Modificar valores pela subrede que deseja que o arduino utilize na rede

mac: Modificar valores após '0x' pelo mac abaixo do shield de ethernet

ip:  Modificar valores pelo ip que deseja que o arduino utilize na rede
```

**5.** Selecionar em 'Tools->Board' o modelo do arduino que irá ser gravado


**6.** Caso necessário escolher em 'Tools->Processor' o processador que está no arduino


**7.** Selecionar em 'Tools->Port' a porta serial do computador onde foi conectado o arduino


**8.** Pressionar o botão '->' abaixo da barra de opções para passar o código para o arduino
