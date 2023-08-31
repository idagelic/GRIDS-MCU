# GRIDS-MCU

## Write Objects

### ElectricityDataDTO
| Field                  | Type   | Default Value  |
|------------------------|--------|----------------|
| counter                | number | 0              |
| session_id             | number | 0              |
| kwh_cumulative_energy  | number | 0              |
| watt_average_power     | number | 0              |
| created_at             | Date   | Current Date   |

### EnergyDeliveryStoppedDTO
| Field                  | Type   | Default Value  |
|------------------------|--------|----------------|
| session_id             | number | 0              |
| reason_for_stop        | number | 0              |

### PowerExceededDTO
| Field                  | Type   | Default Value  |
|------------------------|--------|----------------|
| session_id             | number | 0              |
| amount                 | number | 0              |

### SessionStoppedDTO
| Field                  | Type   | Default Value  |
|------------------------|--------|----------------|
| session_id             | number | 0              |
| reason_for_stop        | number | 0              |
| kwh_energy_delivered   | number | 0              |
| created_at             | Date   | Current Date   |

## Constants

- ENERGY_DELIVERY_NO_INTERNET: 1
- ENERGY_DELIVERY_POWER_EXCEEDED: 2
- SESSION_STOPPED_EXTERNAL_COMMAND: 0
- SESSION_STOPPED_TIME_ELAPSED: 1
- SESSION_STOPPED_ENERGY_EXCEEDED: 2

## Read Objects

### EnergyDeliveryStartDTO
| Field                  | Type   | Default Value  |
|------------------------|--------|----------------|
| energy_delivery_status | number | 1              |

### EnergyDeliveryStopDTO
| Field                  | Type   | Default Value  |
|------------------------|--------|----------------|
| energy_delivery_status | number | 0              |

### FunctionParametersDTO
| Field                  | Type   | Default Value  |
|------------------------|--------|----------------|
| pmax_action_threshold  | number | 0              |
| pmax_action_delay      | number | 0              |
| energy_delivery_stop_delay | number | 0            |
| energy_message_interval | number | 0              |

### PTMaxDTO
| Field                  | Type   | Default Value  |
|------------------------|--------|----------------|
| ptmax                  | number | 0              |
| ptmax_timeout          | Date   | Current Date   |

### RevertToDefaultDTO
| Field                  | Type   | Default Value  |
|------------------------|--------|----------------|
| revert_timeout         | Date   | Current Date   |

### SessionInitDTO
| Field                  | Type   | Default Value  |
|------------------------|--------|----------------|
| session_id             | number | 0              |
| kwh_contracted_energy  | number | 0              |
| watt_pmax              | number | 0              |
| ends_at                | Date   | Current Date   |

### SessionStopDTO
| Field                  | Type   | Default Value  |
|------------------------|--------|----------------|
| session_status         | number | 0              |
