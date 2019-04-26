zabbix_arduino_monitor
=========


**Agente de monitoramento zabbix arduino**

Um sistema de monitoramento de temperatura e corrente de uma sala utilizando de sensores de temperatura e de corrente, o mesmo foi criado para ser utilizado em uma sala de servidor mas o mesmo não contém limitações sob o local onde pode ser implantado desde que exista a possibilidade de conexão dos sensores necessários nos locais onde eles devem medir.

Na implementação são utilizados sensores onewire de temperatura e sensores sct-100 de corrente para o monitoramento. Esses são conectados diretamente à placa ou em uma PCB que as conecta à placa. É importante notar que é necessaria a utilização de resistores e capacitores de acordo com o sensor que é escolhido para utilização em ambas as maneiras de implantação, sendo a PCB inclusa no projeto apenas uma versão que não necessita de fios da maneira manual, sendo por esse motivo uma placa bastante grande.

O codigo do arduino incluso no projeto se conecta à rede utilizando um shield ethernet 2 da adafruit, o mesmo deve ser configurado seguindo as instruções inclusas na pasta que inclui o código fonte, após inserido na placa o mesmo se comporta como um agente zabbix com suas keys próprias.

As keys que são utilizadas no zabbix também estão inclusas no projeto, a pasta 'zabbix_template' inclui um template que pode ser inserido em seu servidor zabbix para facilitar a conexão com o agente no arduino.
