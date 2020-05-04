# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: PepeSmith
# Contributor: Aron Asor <aronasorman at gmail.com>
# Contributor: Chris Brannon <chris@the-brannons.com>
# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>

pkgname=ipython
pkgver=7.14.0
pkgrel=1
pkgdesc="An enhanced Interactive Python shell."
arch=('any')
url="https://ipython.org"
license=('BSD')
depends=('python' 'python-traitlets' 'python-pexpect' 'sqlite'
         'python-setuptools' 'python-pickleshare' 'python-prompt_toolkit'
         'python-jedi' 'python-pygments' 'python-backcall')
optdepends=("python-nose: for IPython's test suite")

# new optional thing: ipyparallel

source=("ipython-$pkgver.tgz::https://github.com/ipython/ipython/archive/$pkgver.tar.gz"
        "https://www.packal.org/sites/default/files/public/styles/icon_large/public/workflow-files/nkeimipynbworkflow/icon/icon.png"
        'https://github.com/ipython/ipython/commit/1e79c167a41d13eee673b8bb54798cb2f920f957.patch') # FS#66516
md5sums=('057266ea0820d5d58551cf4a49592eef'
         '2901d65f1b1fe354e72850085cd1c072'
         '66b946ec2967cda4cf16ba7c86e729f2')

# confirm that an update does not break sage?

prepare() {
  cd "ipython-$pkgver"
  patch -p1 -i ../1e79c167a41d13eee673b8bb54798cb2f920f957.patch
}

package() {
  cd "ipython-$pkgver"
  python3 setup.py install --prefix=/usr --root="$pkgdir" --optimize=1
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
