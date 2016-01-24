# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Florian Walch <florian+aur@fwalch.com>
# Contributor: Florian Hahn <flo@fhahn.com>

pkgname=neovim
pkgver=0.1.1
pkgrel=2
pkgdesc='Fork of Vim aiming to improve user experience, plugins, and GUIs'
arch=('i686' 'x86_64')
url='https://neovim.io'
license=('custom:neovim')
depends=('jemalloc' 'libtermkey' 'libuv' 'msgpack-c' 'unibilium' 'libvterm')
makedepends=('cmake' 'luajit' 'lua51-messagepack' 'lua51-lpeg')
optdepends=('python2-neovim: for Python 2 plugin support (see :help nvim-python)'
            'python-neovim: for Python 3 plugin support (see :help nvim-python)'
            'xclip: for clipboard support (or xsel) (see :help nvim-clipboard)'
            'xsel: for clipboard support (or xclip) (see :help nvim-clipboard)')
source=("https://github.com/neovim/neovim/archive/v${pkgver}.tar.gz"
        msgpack-14-compat.patch::https://github.com/neovim/neovim/commit/feb70192a85d04343ecc383ea9a42aa8cd15e98d.patch)
sha256sums=('f39bcab23457c66ce0d67dcf8029743703f860413db0070f75d4f0ffad27c6c1'
            '16aa4fb704fc613ce4148ec7e0da8458d956022502e1b64f2f72c3d8b90ffc63')
install=neovim.install

prepare() {
  cd "neovim-${pkgver}"
  patch -p1 < "${srcdir}/msgpack-14-compat.patch"
}

build() {
  mkdir -p "${srcdir}/build"
  cd "${srcdir}/build"

  cmake "../neovim-${pkgver}" \
        -DCMAKE_BUILD_TYPE=RelWithDebInfo \
        -DCMAKE_INSTALL_PREFIX=/usr \
        -DENABLE_JEMALLOC=ON
  make
}

check() {
  cd "${srcdir}/build"
  ./bin/nvim --version
  ./bin/nvim --headless -u NONE -i NONE -c ':quit'
}

package() {
  cd "${srcdir}/build"
  make DESTDIR="${pkgdir}" install
  install -Dm644 "${srcdir}/neovim-${pkgver}"/LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}

# vim:set sw=2 sts=2 et:
