# Maintainer: Kyle Keen <keenerd@gmail.com>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: PepeSmith
# Contributor: Aron Asor <aronasorman at gmail.com>
# Contributor: Chris Brannon <chris@the-brannons.com>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>

pkgname=ipython
pkgver=7.24.1
pkgrel=1
pkgdesc="An enhanced Interactive Python shell."
arch=('any')
url="https://ipython.org"
license=('BSD')
depends=('python' 'python-traitlets' 'python-pexpect' 'sqlite'
         'python-pickleshare' 'python-prompt_toolkit'
         'python-jedi' 'python-pygments' 'python-backcall'
         'python-matplotlib-inline')
makedepends=('python-setuptools')
checkdepends=('python-nose' 'python-requests' 'python-testpath'
              'jupyter-nbformat' 'python-ipykernel' 'python-numpy'
              'python-pytest-trio' 'python-matplotlib')
source=("https://files.pythonhosted.org/packages/source/${pkgname::1}/$pkgname/$pkgname-$pkgver.tar.gz"
        "https://www.packal.org/sites/default/files/public/styles/icon_large/public/workflow-files/nkeimipynbworkflow/icon/icon.png")
sha256sums=('9bc24a99f5d19721fb8a2d1408908e9c0520a17fff2233ffe82620847f17f1b6'
            '3c44a6fa1e3a8afc24754c90469404770b639cb960361988999a4cdd677699d8')
b2sums=('ae63d024f488f44dbd61eb9f3e14ac5b8ad801b1db195632c184c6106d4c2e6d6143c1524ae6fc5a2f6f631683b73f241c9115c439c0f97a4fe540cc232fb181'
        'd445e2bc7a037db8715ea103611720e965987e155c32e445b0ef783e519fca8a0301b16c5763fd9a5d8d169c3b0d7b4db6c0bd0f9772842258b135dcb1d6d5a2')

# confirm that an update does not break sage?

build() {
  cd $pkgname-$pkgver
  python setup.py build
}

check() {
  cd $pkgname-$pkgver
  pytest
}

package() {
  cd $pkgname-$pkgver
  export PYTHONHASHSEED=0
  python setup.py install --prefix=/usr --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 docs/source/about/license_and_copyright.rst "$pkgdir/usr/share/licenses/ipython/LICENSE"

  cd "examples/IPython Kernel"
  # FS#45120
  sed -i 's/gnome-netstatus-idle/ipython/' *.desktop
  install -Dm644 ipython.desktop "$pkgdir/usr/share/applications/ipython.desktop"
  #install -Dm644 ipython-qtconsole.desktop "$pkgdir/usr/share/applications/ipython-qtconsole.desktop"
  # FS#47046
  install -Dm644 "$srcdir/icon.png" "$pkgdir/usr/share/pixmaps/ipython.png"

  #cd $srcdir/ipython-$pkgver/IPython/qt/console/resources/icon/
  #install -Dm644 IPythonConsole.svg "$pkgdir/usr/share/icons/hicolor/scalable/apps/ipython.svg"
}
