# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Giovanni Scafora <giovanni@archlinux.org>
# Contributor: Petrov Roman <nwhisper@gmail.com>
# Contributor: Andrea Fagiani <andfagiani _at_ gmail dot com>
# Contributor: Larry Hajali <larryhaja@gmail.com>

pkgbase=calibre
pkgname=calibre
pkgver=5.32.0
pkgrel=1
pkgdesc="Ebook management application"
arch=('x86_64')
url="https://calibre-ebook.com/"
license=('GPL3')
_py_deps=('apsw' 'beautifulsoup4' 'cchardet' 'cssselect' 'css-parser' 'dateutil' 'dnspython'
          'feedparser' 'html2text' 'html5-parser' 'jeepney' 'lxml' 'markdown' 'mechanize' 'msgpack'
          'netifaces' 'unrardll' 'pillow' 'psutil' 'py7zr' 'pychm' 'pygments' 'pyqt5'
          'pyqtwebengine' 'regex' 'zeroconf')
depends=('hunspell' 'hyphen' 'icu' 'jxrlib' 'libmtp' 'libstemmer' 'libusb'
         'libwmf' 'mathjax' 'mtdev' 'optipng' 'podofo'
         "${_py_deps[@]/#/python-}" 'qt5-imageformats' 'qt5-svg' 'ttf-liberation' 'udisks2')
makedepends=('qt5-x11extras' 'sip' 'pyqt-builder' 'xdg-utils' 'rapydscript-ng')
checkdepends=('xorg-server-xvfb')
optdepends=('poppler: required for converting pdf to html'
            'speech-dispatcher: TTS support in the viewer')
conflicts=('calibre-common' 'calibre-python3')
replaces=('calibre-common' 'calibre-python3')
source=("https://download.calibre-ebook.com/${pkgver}/calibre-${pkgver}.tar.xz"
        "https://calibre-ebook.com/signatures/${pkgbase}-${pkgver}.tar.xz.sig")
sha256sums=('3571efc1cc773e453b459096a38b141fd0c7784fb9611505a1f9a55648f47e5e'
            'SKIP')
validpgpkeys=('3CE1780F78DD88DF45194FD706BC317B515ACE7C') # Kovid Goyal (New longer key) <kovid@kovidgoyal.net>

prepare(){
    cd "${pkgbase}-${pkgver}"

    # Desktop integration (e.g. enforce arch defaults)
    # Use uppercase naming scheme, don't delete config files under fakeroot.
    sed -e "/import config_dir/,/os.rmdir(config_dir)/d" \
        -e "s/'ctc-posml'/'text' not in mt and 'pdf' not in mt and 'xhtml'/" \
        -e "s/^Name=calibre/Name=Calibre/g" \
        -i  src/calibre/linux.py

    cd resources

    # Remove unneeded files
    rm ${pkgbase}-portable.* mozilla-ca-certs.pem

    # use system mathjax
    rm -r mathjax
}

build() {
    cd "${pkgbase}-${pkgver}"

    LANG='en_US.UTF-8' python setup.py build
    LANG='en_US.UTF-8' python setup.py gui
    python setup.py liberation_fonts --path-to-liberation_fonts /usr/share/fonts/liberation --system-liberation_fonts
    LANG='en_US.UTF-8' python setup.py mathjax --path-to-mathjax /usr/share/mathjax --system-mathjax
    LANG='en_US.UTF-8' python setup.py rapydscript
}

check() {
    cd "${pkgbase}-${pkgver}"

    _test_excludes=(
        # merely testing if a runtime-optional feature optdepend is importable
        'speech_dispatcher'
        # tests if a completely unused module is bundled
        'pycryptodome'
    )

    # without xvfb-run this fails with much "Control socket failed to recv(), resetting"
    # ERROR: test_websocket_perf (calibre.srv.tests.web_sockets.WebSocketTest)
    # one or two tests are a bit flaky, but the python3 build seems to succeed more often
    LANG='en_US.UTF-8' xvfb-run python setup.py test "${_test_excludes[@]/#/--exclude-test-name=}"
}

package() {
    cd "${pkgbase}-${pkgver}"

    # If this directory doesn't exist, zsh completion won't install.
    install -d "${pkgdir}/usr/share/zsh/site-functions"

    LANG='en_US.UTF-8' python setup.py install \
        --staging-root="${pkgdir}/usr" \
        --prefix=/usr \
        --system-plugins-location=/usr/share/calibre/system-plugins

    cp -a man-pages/ "${pkgdir}/usr/share/man"

    # not needed at runtime
    rm -r "${pkgdir}"/usr/share/calibre/rapydscript/

    # Compiling bytecode FS#33392
    # This is kind of ugly but removes traces of the build root.
    while read -rd '' _file; do
        _destdir="$(dirname "${_file#${pkgdir}}")"
        python3 -m compileall -d "${_destdir}" "${_file}"
        python3 -O -m compileall -d "${_destdir}" "${_file}"
    done < <(find "${pkgdir}"/usr/lib/ -name '*.py' -print0)
}
