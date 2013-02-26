# Contributor: Slash <demodevil5[at]yahoo[dot]com>
# Maintainer: J.W. Birdsong  <jwbirdsongATmailDOTcom>

pkgname=teamspeak3
pkgver=3.0.9.2
pkgrel=1
pkgdesc="TeamSpeak is software for quality voice communication via the Internet"
url="http://www.teamspeak.com/"
license=('custom')
depends=('qt' 'libpulse')
arch=('i686' 'x86_64')
source=("http://teamspeak.gameserver.gamed.de/ts3/releases/${pkgver}/TeamSpeak3-Client-linux_x86-${pkgver}.run" 
\
'teamspeak3.desktop' 'icon.xpm' 'teamspeak3.launcher')


    md5sums=('b9ca1362f6f79644357c5558ee5ddfd2'
           'be58a8798c5d1b7e95a89f6a6482db3e'
           '19f103384e4c1a0aafc8fed44de0c87b'
           '170fcbb1b468ce4f3dba7ee3fb2a1c6d')

    _TSARCH='x86'

    if [ "$CARCH" == "x86_64" ]; then
    
    source[0]="http://teamspeak.gameserver.gamed.de/ts3/releases/${pkgver}/TeamSpeak3-Client-linux_amd64-${pkgver}.run"
      md5sums[0]='a15002b92e3cd4585dc9ce07818bf446'
      _TSARCH='amd64'
    fi
  build() {
    cd ${srcdir}

    # Create Destination Directories
    install -d ${pkgdir}/{usr/bin/,opt/}

    # Make Installer Executable
    chmod +x TeamSpeak3-Client-linux_${_TSARCH}-${pkgver}.run

    # Run Installer
    ./TeamSpeak3-Client-linux_${_TSARCH}-${pkgver}.run --noexec --target teamspeak3

    # Move Program Data to Package Directory
    mv ${srcdir}/teamspeak3/ ${pkgdir}/opt/

    # Remove Bundled Qt Libraries and Symlink system libraries to TS3 Directory
    rm ${pkgdir}/opt/teamspeak3/libQt*
    ln -s /usr/lib/libQtCore.so.4    ${pkgdir}/opt/teamspeak3/libQtCore.so.4
    ln -s /usr/lib/libQtGui.so.4     ${pkgdir}/opt/teamspeak3/libQtGui.so.4
    ln -s /usr/lib/libQtNetwork.so.4 ${pkgdir}/opt/teamspeak3/libQtNetwork.so.4

    # Install Desktop File
    install -D -m644 $srcdir/teamspeak3.desktop \
        ${pkgdir}/usr/share/applications/teamspeak3.desktop

    # Install Icon File
    install -D -m644 $srcdir/icon.xpm \
        ${pkgdir}/usr/share/pixmaps/teamspeak3.xpm

    # Install Custom License
    install -D -m644 ${pkgdir}/opt/teamspeak3/LICENSE \
        ${pkgdir}/usr/share/licenses/${pkgname}/LICENSE

    # Install Client Launcher
    install -D -m755 $srcdir/teamspeak3.launcher \
        ${pkgdir}/usr/bin/teamspeak3
}
# vim:set ts=2 sw=2 et:

