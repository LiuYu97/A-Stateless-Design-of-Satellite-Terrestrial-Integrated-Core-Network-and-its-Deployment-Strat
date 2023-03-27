#include "ns3/application.h"
#include "ns3/event-id.h"
#include "ns3/ptr.h"
#include "ns3/address.h"
#include "ns3/traced-callback.h"

namespace ns3 {

class Socket;
class Packet;

/**
 * \ingroup applications 
 * \defgroup udpecho UdpEcho
 */

/**
 * \ingroup udpecho
 * \brief A Udp Echo server
 *
 * Every packet received is sent back.
 */
class XnSMF : public Application 
{
public:
  /**
   * \brief Get the type ID.
   * \return the object TypeId
   */
  static TypeId GetTypeId (void);
  XnSMF ();
  virtual ~XnSMF ();
  

protected:
  virtual void DoDispose (void);

private:

  virtual void StartApplication (void);
  virtual void StopApplication (void);

  /**
   * \brief Handle a packet reception.
   *
   * This function is called by lower layers.
   *
   * \param socket the socket the packet was received to.
   */
  void HandleRead (Ptr<Socket> socket);

  uint16_t m_port; //!< Port on which we listen for incoming packets.
  Ptr<Socket> m_socket; //!< IPv4 Socket
  //Ptr<Socket> m_dest_socket;
  Ptr<Socket> m_socket6; //!< IPv6 Socket
  //Ptr<Socket> m_dest_socket6; //!< IPv6 Socket
  Address m_local; //!< local multicast address
  //InetSocketAddress dest_address;
  uint32_t p_num;
  Address UPF_address;
  uint16_t UPF_port;
  Address Ground_address;
  uint16_t AMF_port;
  uint16_t m_number; //!< Remote peer port
  uint16_t log_open;
  std::map<std::string, Address> smf_back_amf;
  
  /// Callbacks for tracing the packet Rx events
  TracedCallback<Ptr<const Packet> > m_rxTrace;
  double NF_process_time[3][100];
  /// Callbacks for tracing the packet Rx events, includes source and destination addresses
  TracedCallback<Ptr<const Packet>, const Address &, const Address &> m_rxTraceWithAddresses;
};

} // namespace ns3