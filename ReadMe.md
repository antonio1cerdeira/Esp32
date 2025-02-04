# 📡 Projeto ESP32 com Bluetooth, Touch e Sensor de Força Resistivo (FSR)

## 🔥 Descrição
Este projeto utiliza um **ESP32** para comunicação via **Bluetooth** e integração com um **sensor de força resistivo (FSR)**, um **botão touch**, **LEDs** e um **buzzer**. Os LEDs indicam o nível de força aplicada no sensor, e o buzzer é ativado ao atingir a força máxima.

---

## 🎯 Funcionalidades
- 📡 **Comunicação Bluetooth** para transmissão de dados.
- 🖲️ **Botão touch** para interação com o sistema.
- 🔦 **LEDs indicativos** do nível de força aplicado.
- 🎵 **Buzzer** acionado quando a força máxima é atingida.

---

## 🛠️ Componentes Utilizados
- 🔌 **ESP32** (módulo principal)
- 🎚️ **Sensor de Força Resistivo (FSR)**
- 💡 **LEDs** (para indicar níveis de força)
- 🔊 **Buzzer** (para alerta sonoro)
- 🖲️ **Botão touch** (para reset ou interação)
- 🔋 **Fonte de alimentação 5V**

---

## ⚡ Esquemático de Ligação

### 📌 Conexões Principais:
- **FSR** → Entrada Analógica do ESP32
- **Botão Touch** → Entrada Digital do ESP32
- **LEDs** → Portas Digitais (PWM para controle de brilho)
- **Buzzer** → Porta Digital (ativação quando força máxima for atingida)
- **Bluetooth** → Comunicação serial via software

---

## 🚀 Instalação e Configuração
### 🔹 Requisitos:
1. **Placa ESP32** configurada no Arduino IDE ou PlatformIO.
2. **Bibliotecas necessárias:**
   - `BluetoothSerial.h` (para comunicação Bluetooth)
   - `Arduino.h` (biblioteca base para ESP32)
3. **Código-fonte** carregado na ESP32 via USB.

### 🔹 Como Usar:
1. Conecte os componentes conforme o esquema de ligação.
2. Compile e envie o código para o ESP32.
3. Conecte-se ao dispositivo via Bluetooth (utilize um aplicativo de terminal Bluetooth).
4. Pressione o **botão touch** para resetar o sistema.
5. Aplique força no **sensor FSR** e observe os LEDs indicando o nível.
6. Quando a força máxima for atingida, o **buzzer será acionado**.

## 🎯 Melhorias Futuras
- Implementação de um **display OLED** para exibir a força em tempo real.
- Adicionar **controle via aplicativo móvel**.
- Implementar **alarme sonoro progressivo** com PWM no buzzer.

---

## 📩 Contato
Caso tenha dúvidas ou sugestões, entre em contato!

👨‍💻 **Desenvolvido por:** _[CerdeiraDev]_