# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Giovanni Scafora <giovanni@archlinux.org>
# Contributor: Petrov Roman <nwhisper@gmail.com>
# Contributor: Andrea Fagiani <andfagiani _at_ gmail dot com>
# Contributor: Larry Hajali <larryhaja@gmail.com>

pkgname=calibre
pkgver=3.44.0
pkgrel=2
pkgdesc="Ebook management application"
arch=('x86_64')
url="https://calibre-ebook.com/"
license=('GPL3')
_py_deps=('apsw' 'beautifulsoup4' 'cssselect' 'css-parser' 'dateutil' 'dbus' 'dnspython' 'dukpy'
          'feedparser' 'html2text' 'html5-parser' 'lxml' 'markdown' 'mechanize' 'msgpack'
          'netifaces' 'unrardll' 'pillow' 'psutil' 'pygments' 'pyqt5' 'regex')
depends=('chmlib' 'icu' 'jxrlib' 'libmtp' 'libusbx' 'libwmf' 'mathjax' 'mtdev' 'optipng'
         'podofo' "${_py_deps[@]/#/python2-}" 'qt5-svg' 'qt5-webkit' 'udisks2')
makedepends=('qt5-x11extras' 'rapydscript-ng' 'sip' 'xdg-utils')
checkdepends=('xorg-server-xvfb')
optdepends=('ipython2: to use calibre-debug'
            'poppler: required for converting pdf to html')
source=("https://download.calibre-ebook.com/${pkgver}/calibre-${pkgver}.tar.xz"
        "https://calibre-ebook.com/signatures/${pkgname}-${pkgver}.tar.xz.sig"
        "https://github.com/kovidgoyal/calibre/commit/0a5dc07da1cb0f9409803b4df1a92e497e3c0e95.patch")
sha256sums=('f15354b013cbf4090e1eeefdc150402dac589f51395f9c82424d2e8cec62a38d'
            'SKIP'
            '728509a902267b8fd628884e1040a54f7a6fb03fc2dcbcf2ff7e54be6eae7920')
b2sums=('7eb1412aa5de6ba2f48ea13e922dffff7ace0f4f475832ebe122db967c71df05b6bbb45092bdd53ddfe35d7a0c2af566ed83dde9aac64200d41ea2adc4cb1886'
        'SKIP'
        'fc647f48cc0dfc85028babb1fe0b659820e9f34001611f84eeddd0938465991e3e2e4afb9d256e887585d2e1109091fb03a4248fa2a3efdcf8b04735810d7448')
validpgpkeys=('3CE1780F78DD88DF45194FD706BC317B515ACE7C') # Kovid Goyal (New longer key) <kovid@kovidgoyal.net>

prepare(){
  cd "${pkgname}-${pkgver}"

  # fix build with qt 5.13
  patch -p1 -i ../0a5dc07da1cb0f9409803b4df1a92e497e3c0e95.patch

  # Desktop integration (e.g. enforce arch defaults)
  sed -e "/import config_dir/,/os.rmdir(config_dir)/d" \
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

  # If this directory doesn't exist, zsh completion won't install.
  install -d "${pkgdir}/usr/share/zsh/site-functions"

  LANG='en_US.UTF-8' python2 setup.py install \
    --staging-root="${pkgdir}/usr" \
    --prefix=/usr

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
