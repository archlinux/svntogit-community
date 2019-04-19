# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Giovanni Scafora <giovanni@archlinux.org>
# Contributor: Petrov Roman <nwhisper@gmail.com>
# Contributor: Andrea Fagiani <andfagiani _at_ gmail dot com>
# Contributor: Larry Hajali <larryhaja@gmail.com>

pkgname=calibre
pkgver=3.41.0
pkgrel=1
pkgdesc="Ebook management application"
arch=('x86_64')
url="https://calibre-ebook.com/"
license=('GPL3')
_py_deps=('apsw' 'beautifulsoup4' 'cssselect' 'css-parser' 'dateutil' 'dbus' 'dnspython' 'dukpy'
          'feedparser' 'html2text' 'html5-parser' 'lxml' 'markdown' 'mechanize' 'msgpack'
          'netifaces' 'unrardll' 'pillow' 'psutil' 'pygments' 'pyqt5' 'regex')
depends=('chmlib' 'icu' 'jxrlib' 'libmtp' 'libusbx' 'libwmf' 'mathjax' 'mtdev' 'optipng'
         'podofo' "${_py_deps[@]/#/python2-}" 'qt5-svg' 'qt5-webkit' 'udisks2')
makedepends=('qt5-x11extras' 'sip' 'xdg-utils')
checkdepends=('xorg-server-xvfb')
optdepends=('ipython2: to use calibre-debug'
            'poppler: required for converting pdf to html')
source=("https://download.calibre-ebook.com/${pkgver}/calibre-${pkgver}.tar.xz"
        "https://calibre-ebook.com/signatures/${pkgname}-${pkgver}.tar.xz.sig")
sha256sums=('77788131daaeb53b86333e9fd4a255998705c832f30995d05e01ceed2a47a350'
            'SKIP')
b2sums=('1fcc89d6cd79ca6b578d2816eb9aea8387be21ee1c51495eb83062ee997394774817379ea785cb93f61a721987a1a5b1dbbd55dce3cc469f73aefb1c42cbea49'
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

  # cherry-picked bits of python2-backports.functools_lru_cache
  # needed for frozen builds + beautifulsoup4
  # see https://github.com/kovidgoyal/calibre/commit/b177f0a1096b4fdabd8772dd9edc66662a69e683#commitcomment-33169700
  rm -r src/backports

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
