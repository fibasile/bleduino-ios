//
//  ConnectionManager.h
//  BLEduino
//
//  Created by Ramon Gonzalez on 10/1/13.
//  Copyright (c) 2013 Kytelabs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@protocol LeDiscoveryManagerDelegate <NSObject>
@optional
//Discovering BLEduino and BLE devices.
- (void) didDiscoverBleduino:(CBPeripheral *)bleduino withRSSI:(NSNumber *)RSSI;
- (void) didDiscoverBleduinos:(NSArray *)bleduinosList;
- (void) didDiscoverBleDevice:(CBPeripheral *)bleDevice withRSSI:(NSNumber *)RSSI;
- (void) didDiscoverBleDevices:(NSArray *)devicesList;

//Connecting to BLEduino and BLE devices.
//PENDING: Perhaps all of these should be handled individually.
- (void) didCconnectToBleduino:(CBPeripheral *)bleduino;
- (void) didCconnectToBleduinos:(NSArray *)bleduinosList;
- (void) didCconnectToBleDevice:(CBPeripheral *)bleDevice;
- (void) didCconnectToDevices:(NSArray *)devicesList;


- (void) didFailToConnectToBleduino:(CBPeripheral *)bleduino error:(NSError *)error;

//Disconnecting from BLEduino and BLE devices.
- (void) didDisconnectFromBleduino:(CBPeripheral *)bleduino error:(NSError *)error;
- (void) didDisconnectFromBleduinos:(NSArray *)bleduinosList error:(NSError *)error;
- (void) didDisconnectFromBleDevice:(CBPeripheral *)bleDevice error:(NSError *)error;
- (void) didDisconnectFromDevices:(NSArray *)devicesList error:(NSError *)error;
@end


@interface LeDiscoveryManager : NSObject <CBCentralManagerDelegate>

@property (nonatomic, weak) id <LeDiscoveryManagerDelegate> delegate;

/****************************************************************************/
/*					 Access to the devices and services                     */
/****************************************************************************/
@property (retain, nonatomic) NSMutableArray    *foundBleduinos;
@property (retain, nonatomic) NSMutableArray    *connectedBleduinos;
@property (retain, nonatomic) NSMutableArray	*connectedServices;

/****************************************************************************/
/*					 Central Manager Settings                               */
/****************************************************************************/
@property BOOL scanOnlyForBLEduinos;
@property BOOL notifyConnect;
@property BOOL notifyDisconnect;

/****************************************************************************/
/*								Actions										*/
/****************************************************************************/
- (void) startScanningForBleduinos;
//- (void) startScanningForBleduinoWithServiceUUIDString:(NSString *)uuidString;
//- (void) startScanningForBleduinoWithServicesUUIDStringList:(NSArray *)uuidStringList;
//- (void) startScanningForBleduinoWithServiceUUID:(NSUUID *)uuid;
//- (void) startScanningForBleduinoWithServicesUUID:(NSArray *)uuidList;

//- (void) startScanningForUUIDString:(NSString *)uuidString;
//- (void) startScanningForUUID:(NSUUID *)uuid;

- (void) stopScanning;

- (void) connectBleduino:(CBPeripheral *)bleduino;
//- (void) connectBleduinos:(NSArray *)bleduinoList;

- (void) disconnectBleduino:(CBPeripheral *)bleduino;
//- (void) disconnectBleduinos:(NSArray *)bleduinoList;


/****************************************************************************/
/*				       Access to LeDiscovery instance			     	    */
/****************************************************************************/

+ (id)sharedLeManager;
- (void)dismiss;
//+ (id)sharedBleDevice;
//+ (id)sharedBleduino:(id)identifier;
//+ (id)sharedBleDevice:(id)identifier;

@end
