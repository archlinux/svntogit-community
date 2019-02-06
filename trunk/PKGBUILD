# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Giovanni Scafora <giovanni@archlinux.org>
# Contributor: Petrov Roman <nwhisper@gmail.com>
# Contributor: Andrea Fagiani <andfagiani _at_ gmail dot com>
# Contributor: Larry Hajali <larryhaja@gmail.com>

pkgname=calibre
pkgver=3.39.1
pkgrel=1
pkgdesc="Ebook management application"
arch=('x86_64')
url="https://calibre-ebook.com/"
license=('GPL3')
depends=('python2-six' 'python2-dateutil' 'python2-css-parser' 'python2-dukpy'
         'python2-mechanize' 'podofo' 'libwmf' 'jxrlib' 'mathjax'
         'chmlib' 'python2-lxml' 'libusbx' 'python2-html5-parser'
         'python2-pillow' 'shared-mime-info' 'python2-dnspython' 'python2-msgpack'
         'python2-pyqt5' 'python2-psutil' 'icu' 'libmtp' 'python2-dbus'
         'python2-netifaces' 'python2-cssselect' 'python2-apsw' 'qt5-webkit'
         'qt5-svg' 'python2-regex' 'python2-pygments' 'mtdev' 'python2-unrardll'
         'desktop-file-utils' 'gtk-update-icon-cache' 'optipng' 'udisks2')
makedepends=('qt5-x11extras' 'sip' 'xdg-utils')
checkdepends=('xorg-server-xvfb')
optdepends=('ipython2: to use calibre-debug'
            'poppler: required for converting pdf to html')
source=("https://download.calibre-ebook.com/${pkgver}/calibre-${pkgver}.tar.xz"
        "https://calibre-ebook.com/signatures/${pkgname}-${pkgver}.tar.xz.sig")
sha256sums=('50bb56ca9455464495c646688722cb07199ed74a3a2eb3dc4f3b3e609be68121'
            'SKIP')
validpgpkeys=('3CE1780F78DD88DF45194FD706BC317B515ACE7C') # Kovid Goyal (New longer key) <kovid@kovidgoyal.net>

prepare(){
  cd "${pkgname}-${pkgver}"

  # Desktop integration (e.g. enforce arch defaults)
  sed -e "/self.create_uninstaller()/,/os.rmdir(config_dir)/d" \
      -e "/cc(\['xdg-desktop-menu', 'forceupdate'\])/d" \
      -e "/cc(\['xdg-mime', 'install', MIME\])/d" \
      -e "s/'ctc-posml'/'text' not in mt and 'pdf' not in mt and 'xhtml'/" \
      -e "s/^Name=calibre/Name=Calibre/g" \
      -i  src/calibre/linux.py

  cd resources

  # Remove unneeded files
  rm ${pkgname}-portable.* mozilla-ca-certs.pem

  # tarball cache from calibre 4.x
  rm editor.js viewer.{js,html}

  # use system mathjax
  rm -r mathjax
}

build() {
  cd "${pkgname}-${pkgver}"

  LANG='en_US.UTF-8' python2 setup.py build
  LANG='en_US.UTF-8' python2 setup.py gui
  LANG='en_US.UTF-8' python2 setup.py mathjax --path-to-mathjax /usr/share/mathjax --system-mathjax
  LANG='en_US.UTF-8' python2 setup.py rapydscript
}

check() {
  cd "${pkgname}-${pkgver}"

  # without xvfb-run this fails with much "Control socket failed to recv(), resetting"
  # ERROR: test_websocket_perf (calibre.srv.tests.web_sockets.WebSocketTest)

  LANG='en_US.UTF-8' xvfb-run python2 setup.py test
}

package() {
  cd "${pkgname}-${pkgver}"

  install -d "${pkgdir}/usr/share/zsh/site-functions" \
             "${pkgdir}"/usr/share/{applications,desktop-directories,icons/hicolor}

  install -Dm644 resources/calibre-mimetypes.xml \
    "${pkgdir}/usr/share/mime/packages/calibre-mimetypes.xml"

  XDG_DATA_DIRS="${pkgdir}/usr/share" LANG='en_US.UTF-8' \
    python2 setup.py install --staging-root="${pkgdir}/usr" --prefix=/usr

  cp -a man-pages/ "${pkgdir}/usr/share/man"

  # not needed at runtime
  rm -r "${pkgdir}"/usr/share/calibre/rapydscript/

  # Compiling bytecode FS#33392
  # This is kind of ugly but removes traces of the build root.
  while read -rd '' _file; do
    _destdir="$(dirname "${_file#${pkgdir}}")"
    python2 -m compileall -d "${_destdir}" "${_file}"
    python2 -O -m compileall -d "${_destdir}" "${_file}"
  done < <(find "${pkgdir}"/usr/lib/ -name '*.py' -print0)
}
