
This repository includes machine learning based transmission power prediction models for 4G/5G mobile networks.
The prediction is performed at the basis of typically available passive connectivity indicators (features), such as RSRP, RSRQ, Velocity, Datarate, Uploadsize,...

This includes in particular:

* [c-mnalib](c-mnalib/README.md): Capturing software for future measurement campaigns
* [model](model/README.md): Exported Random Forest model (based on a practical feature subset)
* [rawData](rawData/README.md): Raw data of a measurement campaign between two large cities in Germany
* [rm_processes](rm_processes/README.md): Configuration files for the software Rapid Miner to perform a model synthesis and evaluation based on given training data

## License
See README and LICENSE files in the included subdirectories for license rights and limitations (MIT).