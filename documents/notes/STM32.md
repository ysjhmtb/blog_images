<br>

[Standard Peripheral Libraries와 KEIL을 이용한 ChrisP's STM32F4 속성으로 따라하기](<https://www.youtube.com/playlist?list=PLUaCOzp6U-RrgJmglRkVvQy6gpKhFCTGJ>)

<br>

<br>

[HAL, CubeMX, TrueSTUDIO를 이용한 ChrisP's STM32F4 속성으로 따라하기](<https://www.youtube.com/playlist?list=PLUaCOzp6U-RqMo-QEJQOkVOl1Us8BNgXk>)

<br>

[[HAL, CubeMX, TrueSTUDIO를 이용한 STM32F4 속성 강의 강좌] 0강. TrueSTUDIO 설치 (1)](https://youtu.be/WzmPlObIr_c)

<br>

[[HAL, CubeMX, TrueSTUDIO를 이용한 STM32F4 속성 강의 강좌] 0강. CubeMX 설치 (2)](https://youtu.be/WsO_qSnTTao)

STM32F407VE

<br>

[[HAL, CubeMX, TrueSTUDIO를 이용한 STM32F4 속성 강의 강좌] 1강. GPIO로 LED출력 및 스위치 입력](https://youtu.be/myo3aTcLxzM)

<br>

- Anode가 +3.3V에 연결되어 있고, PD12, PD13, PD14에 Cathode가 연결.
- RCC >> Crystal / Ceramic Resonator >> Input frequency 8 >> HSE >> HCLK 168
- PE3, PC15, PD4, PD10  >> GPIO Input    
- PD12, PD13, PD14 >> GPIO Output
- PC6, PB0, PB5 >> GPIO Output
- Generate Code >>  Toolchain >> TrudSTUDIO
- Generate peripheral initialization as a pair of .c/.h files per peripheral

```C
/* Initialize all configured peripherals */
MX_GPIO_Init();

/* USER CODE BEGIN 2 */
HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);

/* USER CODE END 2 */

/* Infinite loop */
/* USER CODE BEGIN WHILE */
while(1)
{
  // LED on
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_RESET);
  
  HAL_Delay(1000);
  
  // LED off
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, GPIO_PIN_SET);
  
  HAL_Delay(1000); 
  
  if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3) == GPIO_PIN_SET) // SW pressed
  {
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_RESET);
  }
  else
  {
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, GPIO_PIN_SET);
  }
}

/* USER CODE END WHILE */
```

