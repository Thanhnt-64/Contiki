/* Sense keys */
#define SCSI_SENSE_KEY_NO_SENSE		0x0
#define SCSI_SENSE_KEY_RECOVERED_ERROR	0x1
#define SCSI_SENSE_KEY_NOT_READY	0x2
#define SCSI_SENSE_KEY_MEDIUM_ERROR	0x3
#define SCSI_SENSE_KEY_HARDWARE_ERROR	0x4
#define SCSI_SENSE_KEY_ILLEGAL_REQUEST	0x5
#define SCSI_SENSE_KEY_UNIT_ATTENTION	0x6
#define SCSI_SENSE_KEY_DATA_PROTECT	0x7
#define SCSI_SENSE_KEY_BLANK_CHECK	0x8
#define SCSI_SENSE_KEY_VENDOR_SPECIFIC	0x9
#define SCSI_SENSE_KEY_COPY_ABORTED	0xA
#define SCSI_SENSE_KEY_ABORTED_COMMAND	0xB
#define SCSI_SENSE_KEY_VOLUME_OVERFLOW	0xD
#define SCSI_SENSE_KEY_MISCOMPARE	0xE

/* Additional sense codes */
#define SCSI_ASC_NO_SENSE 0x0000
#define SCSI_ASC_FILEMARK_DETECTED 0x0001
#define SCSI_ASC_END_OF_MEDIUM_DETECTED 0x0002
#define SCSI_ASC_BEGINNING_OF_MEDIUM_DETECTED 0x0004
#define SCSI_ASC_END_OF_DATA_DETECTED 0x0005
#define SCSI_ASC_PERIPHERAL_DEVICE_WRITE_FAULT 0x0300
#define SCSI_ASC_NO_WRITE_CURRENT 0x0301
#define SCSI_ASC_EXCESSIVE_WRITE_ERRORS 0x0302
#define SCSI_ASC_NOT_READY_CAUSE_NOT_REPORTABLE 0x0400
#define SCSI_ASC_IN_PROCESS_OF_BECOMING_READY 0x0401
#define SCSI_ASC_NOT_READY_INITIALIZING_COMMAND_REQUIRED 0x0402
#define SCSI_ASC_NOT_READY_MANUAL_INTERVENTION_REQUIRED 0x0403
#define SCSI_ASC_NOT_READY_FORMAT_IN_PROGRESS 0x0404
#define SCSI_ASC_COMMUNICATION_FAILURE 0x0800
#define SCSI_ASC_COMMUNICATION_TIME_OUT 0x0801
#define SCSI_ASC_COMMUNICATION_PARITY_ERROR 0x0802
#define SCSI_ASC_TRACK_FOLLOWING_ERROR 0x0900
#define SCSI_ASC_ERROR_LOG_OVERFLOW 0x0a00
#define SCSI_ASC_WRITE_ERROR 0x0c00
#define SCSI_ASC_UNRECOVERED_READ_ERROR 0x1100
#define SCSI_ASC_READ_RETRIES_EXHAUSTED 0x1101
#define SCSI_ASC_ERROR_TOO_LONG_TO_CORRECT 0x1102
#define SCSI_ASC_MULTIPLE_READ_ERRORS 0x1103
#define SCSI_ASC_INCOMPLETE_BLOCK_READ 0x1108
#define SCSI_ASC_NO_GAP_FOUND 0x1109
#define SCSI_ASC_MISCORRECTED_ERROR 0x110a
#define SCSI_ASC_RECORDED_ENTITY_NOT_FOUND 0x1400
#define SCSI_ASC_RECORD_NOT_FOUND 0x1401
#define SCSI_ASC_FILEMARK_NOT_FOUND 0x1402
#define SCSI_ASC_END_OF_DATA_NOT_FOUND 0x1403
#define SCSI_ASC_BLOCK_SEQUENCE_ERROR 0x1404
#define SCSI_ASC_RANDOM_POSITIONING_ERROR 0x1500
#define SCSI_ASC_MECHANICAL_POSITIONING_ERROR 0x1501
#define SCSI_ASC_POSITIONING_ERROR_DETECTED_BY_READ_OF_MEDIUM 0x1502
#define SCSI_ASC_RECOVERED_DATA_WITH_NO_ERROR_CORRECTION_APPLIED 0x1700
#define SCSI_ASC_RECOVERED_DATA_WITH_RETRIES 0x1701
#define SCSI_ASC_RECOVERED_DATA_WITH_POSITIVE_HEAD_OFFSET 0x1702
#define SCSI_ASC_RECOVERED_DATA_WITH_NEGATIVE_HEAD_OFFSET 0x1703
#define SCSI_ASC_RECOVERED_DATA_WITH_ERROR_CORRECTION_APPLIED 0x1800
#define SCSI_ASC_DEFECTLIST_ERROR 0x1900
#define SCSI_ASC_PARAMETER_LIST_LENGTH_ERROR 0x1a00
#define SCSI_ASC_INVALID_COMMAND_OPERATION_CODE 0x2000
#define SCSI_ASC_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE 0x2100
#define SCSI_ASC_INVALID_FIELD_IN_CDB 0x2400
#define SCSI_ASC_LOGICAL_UNIT_NOT_SUPPORTED 0x2500
#define SCSI_ASC_INVALID_FIELD_IN_PARAMETER_LIST 0x2600
#define SCSI_ASC_PARAMETER_NOT_SUPPORTED 0x2601
#define SCSI_ASC_PARAMETER_VALUE_INVALID 0x2602
#define SCSI_ASC_THRESHOLD_PARAMETERS_NOT_SUPPORTED 0x2603
#define SCSI_ASC_WRITE_PROTECTED 0x2700
#define SCSI_ASC_NOT_READY_TO_READY_TRANSITION 0x2800
#define SCSI_ASC_PARAMETERS_CHANGED 0x2a00
#define SCSI_ASC_MODE_PARAMETERS_CHANGED 0x2a01
#define SCSI_ASC_OVERWRITE_ERROR_ON_UPDATE_IN_PLACE 0x2d00
#define SCSI_ASC_POWERON_RESET_OR_DEVICE_RESET_OCCURRED 0x2900
#define SCSI_ASC_INCOMPATIBLE_MEDIUM_INSTALLED 0x3000
#define SCSI_ASC_CANNOT_READ_MEDIUM_UNKNOWN_FORMAT 0x3001
#define SCSI_ASC_CANNOT_READ_MEDIUM_INCOMPATIBLE_FORMAT 0x3002
#define SCSI_ASC_CLEANING_CARTRIDGE_INSTALLED 0x3003
#define SCSI_ASC_MEDIUM_FORMAT_CORRUPTED 0x3100
#define SCSI_ASC_TAPE_LENGTH_ERROR 0x3300
#define SCSI_ASC_ROUNDED_PARAMETER 0x3700
#define SCSI_ASC_SAVING_PARAMETERS_NOT_SUPPORTED 0x3900
#define SCSI_ASC_MEDIUM_NOT_PRESENT 0x3a00
#define SCSI_ASC_SEQUENTIAL_POSITIONING_ERROR 0x3b00
#define SCSI_ASC_TAPE_POSITION_ERROR_AT_BEGINNING_OF_MEDIUM 0x3b01
#define SCSI_ASC_TAPE_POSITION_ERROR_AT_END_OF_MEDIUM 0x3b02
#define SCSI_ASC_REPOSITION_ERROR 0x3b08
#define SCSI_ASC_NOT_SELF_CONFIGURED_YET 0x3e00
#define SCSI_ASC_OPERATING_CONDITIONS_HAVE_CHANGED 0x3f00
#define SCSI_ASC_MICROCODE_HAS_BEEN_CHANGED 0x3f01
#define SCSI_ASC_INQUIRY_DATA_HAS_CHANGED 0x3f03
/* 40 NN DIAGNOSTIC FAILURE ON COMPONENT NN (80H-FF H) */
#define SCSI_ASC_INTERNAL_FAILURE 0x4400
#define SCSI_ASC_UNSUCCESSFUL_DEVICE_RESET 0x4600
#define SCSI_ASC_FAILED_SELF_CONFIGURATION 0x4c00
#define SCSI_ASC_OVERLAPPED_COMMANDS_ATTEMPTED 0x4e00
#define SCSI_ASC_WRITE_APPEND_ERROR 0x5000
#define SCSI_ASC_WRITE_APPEND_POSITION_ERROR 0x5001
#define SCSI_ASC_POSITION_ERROR_RELATED_TO_TIMING 0x5002
#define SCSI_ASC_ERASE_FAILURE 0x5100
#define SCSI_ASC_CARTRIDGE_FAULT 0x5200
#define SCSI_ASC_MEDIA_LOAD_EJECT_FAILED 0x5300
#define SCSI_ASC_UNLOAD_TAPE_FAILURE 0x5301
#define SCSI_ASC_MEDIUM_REMOVAL_PREVENTED 0x5302
#define SCSI_ASC_OPERATOR_REQUEST_OR_STATE_CHANGE_INPUT 0x5a00
#define SCSI_ASC_OPERATOR_MEDIUM_REMOVAL_REQUEST 0x5a01
#define SCSI_ASC_OPERATOR_SELECTED_WRITE_PROTECT 0x5a01
#define SCSI_ASC_OPERATOR_SELECTED_WRITE_PERMIT 0x5a03
#define SCSI_ASC_LOG_EXCEPTION 0x5b00
#define SCSI_ASC_THRESHOLD_CONDITION_MET 0x5b01
#define SCSI_ASC_LOG_COUNTER_AT_MAXIMUM 0x5b02
#define SCSI_ASC_LOG_LIST_CODES_EXHAUSTED 0x5b03
/*
70 NN DECOMPRES S ION EXCEP TION SHORT ALGORITHM ID OF NN
71 00 DECOMPRES S ION EXCEP TION LONG ALGORITHM ID
*/

