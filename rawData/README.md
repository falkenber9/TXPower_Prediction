Raw data used for model synthesis of transmission power predictor
=================================================================

## Data traces

The provided trace file was captured in February and March 2018 and includes a main trajectory between the two German cities Dortmund and Hamm.

## Data format for traces

1. tx_power:		Transmission Power [dBm], (**LABEL**)
*  pcc_rsrp:		Reference Signal Received Power [dBm], (Signal strength)
*  pcc_rssi:		Received Signal Strength Indicator [dBm], (Signal strength)
*  rsrq:		Reference Signal Received Quality [dB], (Signal quality)
*  sinr:		Signal to Noise and Interference Ratio [dB], (Signal quality)
*  lte_band:		EUTRA Band Index (Represents operating frequency band)
*  lte_bw_MHz:		Bandwidth [MHz], (Larger bandwidths allow higher data rates)
*  nof_intrafreq_neighbours:	Number of (potentially interfering) neighbour cells 
*  nof_interfreq_neighbours:	Number of cells at other frequencies (same operator)
*  velocity_h:		Horizontal velocity from GPS [m/s], (Mobility)
*  datarate:		Datarate [Byte/s]
*  upload_size:		Initial upload file size [MB], (small files may be affected by slow-start)
*  time_sec:		Unix timestamp in [s]
*  lte_rx_chan:		LTE receive channel
*  lte_tx_chan:		LTE transmission channel
*  tac:			Cell's tracking area code
*  cell_id:		Cell ID
*  latitude:		GPS latitude
*  longitude:		GPS longitude

## License

See the [LICENSE](LICENSE.md) file for license rights and limitations (MIT).