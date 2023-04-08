# Maintainer: Frederik Schwan <freswa at archlinux dot org>
# Contributor: Christian Rebischke <chris.rebischke@archlinux.org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Daniel Micay <danielmicay@gmail.com>
# Contributor: Jonathan Wiersma <archaur at jonw dot org>

pkgbase=virt-manager
pkgname=(virt-install virt-manager)
pkgver=4.1.0
pkgrel=2
arch=('any')
url='https://virt-manager.org/'
license=('GPL')
makedepends=('python-docutils' 'python-setuptools')
checkdepends=('python-pytest' 'libosinfo' 'libvirt-python' 'python-gobject' 'python-requests' 'cpio' 'cdrtools')
optdepends=('x11-ssh-askpass: provide password for remote machines connected via ssh tunnel')
source=("https://releases.pagure.org/virt-manager/virt-manager-${pkgver}.tar.gz")
b2sums=('1b4203be81bd7b82251225d691a4d9068f268e610f049bcadb96de5b539e964ca0b001f22f06ddd8266b58b079f60046f6d11942a1e4eadbc43f0607c46bbddd')

build() {
  cd ${pkgbase}-${pkgver}
  python setup.py configure --default-hvs qemu,lxc
  python setup.py build
}

package_virt-install() {
  pkgdesc='Command line tool for creating new KVM , Xen, or Linux container guests using the libvirt hypervisor'
  depends=('libosinfo' 'libvirt-python' 'python-gobject' 'python-requests' 'cpio' 'libisoburn')

  cd ${pkgbase}-${pkgver}
  python setup.py --no-update-icon-cache --no-compile-schemas install --root "${pkgdir}"
  python -m compileall "${pkgdir}"/usr/share/virt-manager
  python -O -m compileall "${pkgdir}"/usr/share/virt-manager

  # Split virt-manager
  [[ -d "${srcdir}"/virt-manager ]] && rm -r "${srcdir}"/virt-manager/
  mkdir -p "${srcdir}"/split/usr/{bin,share/{man/man1,virt-manager}}
  mv "${pkgdir}"/usr/bin/virt-manager "${srcdir}"/split/usr/bin/
  mv "${pkgdir}"/usr/share/{applications,glib-2.0,icons,metainfo} "${srcdir}"/split/usr/share/
  mv "${pkgdir}"/usr/share/man/man1/virt-manager.1 "${srcdir}"/split/usr/share/man/man1/
  mv "${pkgdir}"/usr/share/virt-manager/{icons,ui,virtManager} "${srcdir}"/split/usr/share/virt-manager/
}

package_virt-manager() {
  pkgdesc='Desktop user interface for managing virtual machines'
  depends=("virt-install=${pkgver}" 'gtk-vnc' 'libvirt-glib' 'spice-gtk' 'vte3' 'python-cairo' 'gtksourceview4')

  mv -v split/* "${pkgdir}/"
}
