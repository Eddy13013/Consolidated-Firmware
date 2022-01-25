#include "App_SetPeriodicCanSignals.h"
#include "App_SharedSetPeriodicCanSignals.h"
#include "App_InRangeCheck.h"

void App_SetPeriodicCanSignals_Imd(
    struct BmsCanTxInterface *can_tx,
    struct Imd *              imd)
{
    App_CanTx_SetPeriodicSignal_SECONDS_SINCE_POWER_ON(
        can_tx, App_Imd_GetSecondsSincePowerOn(imd));
    App_CanTx_SetPeriodicSignal_FREQUENCY(can_tx, App_Imd_GetPwmFrequency(imd));
    App_CanTx_SetPeriodicSignal_DUTY_CYCLE(
        can_tx, App_Imd_GetPwmDutyCycle(imd));

    const struct Imd_Condition condition = App_Imd_GetCondition(imd);
    App_CanTx_SetPeriodicSignal_CONDITION(can_tx, (uint8_t)condition.name);

    App_CanTx_SetPeriodicSignal_VALID_DUTY_CYCLE(
        can_tx, condition.pwm_encoding.valid_duty_cycle);

    switch (condition.name)
    {
        case IMD_NORMAL:
        {
            if (condition.pwm_encoding.valid_duty_cycle == true)
            {
                App_CanTx_SetPeriodicSignal_INSULATION_MEASUREMENT_DCP_10_HZ(
                    can_tx,
                    condition.pwm_encoding.insulation_measurement_dcp_kohms);
            }
        }
        break;
        case IMD_UNDERVOLTAGE_DETECTED:
        {
            if (condition.pwm_encoding.valid_duty_cycle == true)
            {
                App_CanTx_SetPeriodicSignal_INSULATION_MEASUREMENT_DCP_20_HZ(
                    can_tx,
                    condition.pwm_encoding.insulation_measurement_dcp_kohms);
            }
        }
        break;
        case IMD_SST:
        {
            App_CanTx_SetPeriodicSignal_SPEED_START_STATUS_30_HZ(
                can_tx, condition.pwm_encoding.speed_start_status);
        }
        break;
        case IMD_SHORT_CIRCUIT:
        case IMD_DEVICE_ERROR:
        case IMD_EARTH_FAULT:
        case IMD_INVALID:
        {
            // Nothing to do for conditions that don't carry a payload
        }
        break;
    }
}

void App_SetPeriodicSignals_CellMonitorsInRangeChecks(
    struct BmsCanTxInterface *const  can_tx,
    const struct CellMonitors *const cell_monitors)
{
    App_SetPeriodicCanSignals_InRangeCheck(
        can_tx,
        App_CellMonitors_GetCellMonitor0DieTempInRangeCheck(cell_monitors),
        App_CanTx_SetPeriodicSignal_CELL_MONITOR_0_DIE_TEMPERATURE,
        App_CanTx_SetPeriodicSignal_CELL_MONITOR_0_DIE_TEMP_OUT_OF_RANGE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_0_DIE_TEMP_OUT_OF_RANGE_OK_CHOICE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_0_DIE_TEMP_OUT_OF_RANGE_UNDERFLOW_CHOICE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_0_DIE_TEMP_OUT_OF_RANGE_OVERFLOW_CHOICE);

    App_SetPeriodicCanSignals_InRangeCheck(
        can_tx,
        App_CellMonitors_GetCellMonitor1DieTempInRangeCheck(cell_monitors),
        App_CanTx_SetPeriodicSignal_CELL_MONITOR_1_DIE_TEMPERATURE,
        App_CanTx_SetPeriodicSignal_CELL_MONITOR_1_DIE_TEMP_OUT_OF_RANGE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_1_DIE_TEMP_OUT_OF_RANGE_OK_CHOICE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_1_DIE_TEMP_OUT_OF_RANGE_UNDERFLOW_CHOICE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_1_DIE_TEMP_OUT_OF_RANGE_OVERFLOW_CHOICE);

    App_SetPeriodicCanSignals_InRangeCheck(
        can_tx,
        App_CellMonitors_GetCellMonitor2DieTempInRangeCheck(cell_monitors),
        App_CanTx_SetPeriodicSignal_CELL_MONITOR_2_DIE_TEMPERATURE,
        App_CanTx_SetPeriodicSignal_CELL_MONITOR_2_DIE_TEMP_OUT_OF_RANGE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_2_DIE_TEMP_OUT_OF_RANGE_OK_CHOICE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_2_DIE_TEMP_OUT_OF_RANGE_UNDERFLOW_CHOICE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_2_DIE_TEMP_OUT_OF_RANGE_OVERFLOW_CHOICE);

    App_SetPeriodicCanSignals_InRangeCheck(
        can_tx,
        App_CellMonitors_GetCellMonitor3DieTempInRangeCheck(cell_monitors),
        App_CanTx_SetPeriodicSignal_CELL_MONITOR_3_DIE_TEMPERATURE,
        App_CanTx_SetPeriodicSignal_CELL_MONITOR_3_DIE_TEMP_OUT_OF_RANGE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_3_DIE_TEMP_OUT_OF_RANGE_OK_CHOICE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_3_DIE_TEMP_OUT_OF_RANGE_UNDERFLOW_CHOICE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_3_DIE_TEMP_OUT_OF_RANGE_OVERFLOW_CHOICE);

    App_SetPeriodicCanSignals_InRangeCheck(
        can_tx,
        App_CellMonitors_GetCellMonitor4DieTempInRangeCheck(cell_monitors),
        App_CanTx_SetPeriodicSignal_CELL_MONITOR_4_DIE_TEMPERATURE,
        App_CanTx_SetPeriodicSignal_CELL_MONITOR_4_DIE_TEMP_OUT_OF_RANGE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_4_DIE_TEMP_OUT_OF_RANGE_OK_CHOICE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_4_DIE_TEMP_OUT_OF_RANGE_UNDERFLOW_CHOICE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_4_DIE_TEMP_OUT_OF_RANGE_OVERFLOW_CHOICE);

    App_SetPeriodicCanSignals_InRangeCheck(
        can_tx,
        App_CellMonitors_GetCellMonitor5DieTempInRangeCheck(cell_monitors),
        App_CanTx_SetPeriodicSignal_CELL_MONITOR_5_DIE_TEMPERATURE,
        App_CanTx_SetPeriodicSignal_CELL_MONITOR_5_DIE_TEMP_OUT_OF_RANGE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_5_DIE_TEMP_OUT_OF_RANGE_OK_CHOICE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_5_DIE_TEMP_OUT_OF_RANGE_UNDERFLOW_CHOICE,
        CANMSGS_BMS_NON_CRITICAL_ERRORS_CELL_MONITOR_5_DIE_TEMP_OUT_OF_RANGE_OVERFLOW_CHOICE);
}
