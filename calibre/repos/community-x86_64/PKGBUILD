# Maintainer: Jelle van der Waa <jelle@vdwaa.nl>
# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred dot com>
# Contributor: Giovanni Scafora <giovanni@archlinux.org>
# Contributor: Petrov Roman <nwhisper@gmail.com>
# Contributor: Andrea Fagiani <andfagiani _at_ gmail dot com>
# Contributor: Larry Hajali <larryhaja@gmail.com>

pkgbase=calibre
pkgname=('calibre' 'calibre-common' 'calibre-python3')
pkgver=4.5.0
pkgrel=1
pkgdesc="Ebook management application"
arch=('x86_64')
url="https://calibre-ebook.com/"
license=('GPL3')
_py_deps=('apsw' 'beautifulsoup4' 'cssselect' 'css-parser' 'dateutil' 'dbus' 'dnspython'
          'feedparser' 'html2text' 'html5-parser' 'lxml' 'markdown' 'mechanize' 'msgpack'
          'netifaces' 'unrardll' 'pillow' 'psutil' 'pygments' 'pyqt5' 'pyqtwebengine' 'regex')
_py3_deps=("${_py_deps[@]}" 'zeroconf')
depends=('chmlib' 'hunspell' 'icu' 'jxrlib' 'libmtp' 'libusbx' 'libwmf' 'mathjax2' 'mtdev' 'optipng'
         'podofo' 'qt5-svg' 'udisks2')
makedepends=("${_py_deps[@]/#/python2-}" "${_py3_deps[@]/#/python-}" 'qt5-x11extras'
             'rapydscript-ng' 'sip' 'xdg-utils')
checkdepends=('xorg-server-xvfb')
source=("https://download.calibre-ebook.com/${pkgver}/calibre-${pkgver}.tar.xz"
        "https://calibre-ebook.com/signatures/${pkgbase}-${pkgver}.tar.xz.sig"
        "calibre-alternatives.sh")
sha256sums=('8c894bd38ed3f14de9723f6a78db81791c8b5cd27cffd36b37bf79a2fc15e78e'
            'SKIP'
            '1a3b24fb8a4d80dcd791842c4049e8519b9297f1199ef323ac678509f0290573')
b2sums=('b742f897b45e3832e5d8ebec93d8223973b6f5b6d6b3074a07e529eb4b823fa63cbf55c2d6b46ee7e0b5868dc45a858d0a841ce6b9a071ebc27a8977c44b00c6'
        'SKIP'
        'eaf6ee113e24dbf4ac045f4bef6c2b83424cba3aac52f967d0aca8a27356c053b4fc903e2b857c981bfe9c6cb600701ef640facd3df00d3225b2237ee927f5b1')
validpgpkeys=('3CE1780F78DD88DF45194FD706BC317B515ACE7C') # Kovid Goyal (New longer key) <kovid@kovidgoyal.net>

prepare(){
    cd "${pkgbase}-${pkgver}"

    # Desktop integration (e.g. enforce arch defaults)
    # Use uppercase naming scheme, don't delete config files under fakeroot.
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
    rm ${pkgbase}-portable.* mozilla-ca-certs.pem

    # use system mathjax
    rm -r mathjax
}

build() {
    cd "${pkgbase}-${pkgver}"

    LANG='en_US.UTF-8' python2 setup.py build
    LANG='en_US.UTF-8' python2 setup.py gui
    LANG='en_US.UTF-8' python2 setup.py mathjax --path-to-mathjax /usr/share/mathjax2 --system-mathjax
    LANG='en_US.UTF-8' python2 setup.py rapydscript

    LANG='en_US.UTF-8' CALIBRE_PY3_PORT=1 python3 setup.py build
}

check() {
    cd "${pkgbase}-${pkgver}"

    # without xvfb-run this fails with much "Control socket failed to recv(), resetting"
    # ERROR: test_websocket_perf (calibre.srv.tests.web_sockets.WebSocketTest)
    # one or two tests are a bit flaky, but the python3 build seems to succeed more often
    LANG='en_US.UTF-8' xvfb-run env CALIBRE_PY3_PORT=1 python3 setup.py test
    LANG='en_US.UTF-8' xvfb-run python2 setup.py test
}

package_calibre-common() {
    pkgdesc+=" (common files)"
    optdepends=('poppler: required for converting pdf to html')
    conflicts=("calibre<${pkgver}-${pkgrel}")
    install=calibre-common.install
    cd "${pkgbase}-${pkgver}"

    # If this directory doesn't exist, zsh completion won't install.
    install -d "${pkgdir}/usr/share/zsh/site-functions"

    LANG='en_US.UTF-8' python2 setup.py install \
        --staging-root="${pkgdir}/usr" \
        --prefix=/usr

    for bin in "${pkgdir}"/usr/bin/*; do
        ln -sfT "/usr/lib/calibre/bin/${bin##*/}" "${bin}"
    done

    install -Dm755 "${srcdir}"/calibre-alternatives.sh "${pkgdir}"/usr/bin/calibre-alternatives

    cp -a man-pages/ "${pkgdir}/usr/share/man"

    # not needed at runtime
    rm -r "${pkgdir}"/usr/share/calibre/rapydscript/

    #cleanup overlapping files
    rm -r "${pkgdir}"/usr/lib/python2.7
    rm -r "${pkgdir}"/usr/lib/calibre/calibre/plugins/
    find "${pkgdir}" -type f -name '*.py[co]' -delete
}

package_calibre() {
    pkgdesc+=" (python2 build)"
    depends=('calibre-common' "${_py_deps[@]/#/python2-}")
    optdepends+=('ipython2: to use calibre-debug')
    install=calibre.install

    cd "${pkgbase}-${pkgver}"

    LANG='en_US.UTF-8' python2 setup.py install \
        --staging-root="${pkgdir}/usr" \
        --prefix=/usr \
        --no-postinstall \
        --bindir=/usr/lib/calibre/bin-py2 \
        --staging-bindir="${pkgdir}/usr/lib/calibre/bin-py2" \
        --staging-sharedir="${srcdir}"/temp

    # Compiling bytecode FS#33392
    # This is kind of ugly but removes traces of the build root.
    while read -rd '' _file; do
        _destdir="$(dirname "${_file#${pkgdir}}")"
        python2 -m compileall -d "${_destdir}" "${_file}"
        python2 -O -m compileall -d "${_destdir}" "${_file}"
    done < <(find "${pkgdir}"/usr/lib/ -name '*.py' -print0)

    # cleanup overlapping files
    find "${pkgdir}"/usr/lib/calibre -name '*.py' -delete
    rm -r "${pkgdir}"/usr/lib/calibre/calibre/plugins/3/
}

package_calibre-python3() {
    pkgdesc+=" (experimental python3 port)"
    depends=('calibre-common' "${_py3_deps[@]/#/python-}")
    optdepends+=('ipython: to use calibre-debug')
    install=calibre.install

    cd "${pkgbase}-${pkgver}"

    LANG='en_US.UTF-8' CALIBRE_PY3_PORT=1 python3 setup.py install \
        --staging-root="${pkgdir}/usr" \
        --prefix=/usr \
        --no-postinstall \
        --bindir=/usr/lib/calibre/bin-py3 \
        --staging-bindir="${pkgdir}/usr/lib/calibre/bin-py3" \
        --staging-sharedir="${srcdir}"/temp

    # Compiling bytecode FS#33392
    # This is kind of ugly but removes traces of the build root.
    while read -rd '' _file; do
        _destdir="$(dirname "${_file#${pkgdir}}")"
        python3 -m compileall -d "${_destdir}" "${_file}"
        python3 -O -m compileall -d "${_destdir}" "${_file}"
    done < <(find "${pkgdir}"/usr/lib/ -name '*.py' -print0)

    # cleanup overlapping files
    find "${pkgdir}"/usr/lib/calibre -name '*.py' -delete
    rm "${pkgdir}"/usr/lib/calibre/calibre/plugins/*.so
}
