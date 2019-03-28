USB Notes
=========

## Descriptors

###### USB Interface
Generally, a unit of functionality on a USB device. Most classes use multiple endpoints on a single interface.
USB CDC-ACM (Virtual Serial) class devices break this assumption by utilizing two interfaces.

###### Composite Device
A USB device with multiple interfaces serving different functions.

###### Interface Association Descriptor
A special descriptor added to USB to allow Composite Devices where one of the units of functionality uses
multiple interfaces, such as CDC-ACM. This allows multiple interfaces to be logically grouped together.

##### Windows Compatibility

###### MS OS 20 Descriptor Set
A set of custom Descriptors used to control device behavior on Windows, including selecting drivers to load as well as 
setting registry values. These are retrieved via a vendor-specific control request, must like the WebUSB descriptor.

###### BOS Descriptor
Windows looks for a Platform Capability BOS Descriptor which defines the size of the MS OS 20 Descriptor Set, along
with a magic byte to identify the type of request (to differentiate from other vendor requests).

## Windows Access Strategy

The device defines the required CDC-ACM interfaces and endpoints, but also an alternative for the 2nd (data transfer) 
interface with no endpoints. For the additional WebUSB interface, the default is no endpoints, but an alternative
for that interface defines two endpoints that match those used by the CDC-ACM data transfer interface, albeit with
vendor class values so the endpoints can be accessed by WinUSB.
